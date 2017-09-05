#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "list.h"
#include "stack.h"
#include "dynamicarray.h"
#include "expressionsolver.h"


#define NUM_THREADS     5


void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   usleep(5000);
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

void destr(void *s)
{
  free((my*)s);
  return;
}



int main (int argc, char *argv[])
{


  my *m1 = malloc(sizeof(my));
  m1->c = '1';
  m1->count = 10;
  my *m2 = malloc(sizeof(my));
  m2->c = '2';
  m2->count = 20;
  my *m3 = malloc(sizeof(my));
  m3->c = '3';
  m3->count = 30;
  my *m4 = malloc(sizeof(my));
  m4->c = '4';
  m4->count = 40;
/*------ExpressionSolver------------*/
ExpressionSolver *es = new_expressionsolver(1000);
char in[] = "(5*(((9+8)*(4*6))+7))";
char* out = (char*)malloc(100);
es->postfixTransform(es,in,out);
double res = es->postfixCalc(es,out);
delete_expressionsolver(es);
/*------DynamicArray----------------*/
  DynamicArray* array = new_DynamicArray(4);
  array->add(array,1);
  array->add(array,2);
  array->add(array,3);
  array->add(array,4);

  array->swap(array,1,3);
  array->swap(array,0,2);

/*-------------stack----------------*/
  Stack* stk;
  my *tst;
  stk = new_stack(destr);
  stk->push(stk,m1);
  stk->push(stk,m2);
  stk->push(stk,m3);
  stk->push(stk,m4);

  tst = stk->pop(stk);
  tst = stk->pop(stk);
  tst = stk->pop(stk);
  tst = stk->pop(stk);


  tst = stk->pop(stk);
  delete_stack(stk);
/*--------------list----------------*/
  List* lst;
  lst = new_list(destr);
  lst->ins_next(lst,NULL,m1);
  lst->ins_next(lst,NULL,m2);
  lst->ins_next(lst,NULL,m3);
  lst->ins_next(lst,NULL,m4);

  my* removed;
  removed = lst->rem_next(lst,NULL);

  int size = lst->size;
  my* tmp = lst->data(lst,2);
  delete_list(lst);
/*-------------threads---------------------*/
  int t;
  int rc;
  pthread_t threads[NUM_THREADS];
   for(t=0; t<NUM_THREADS; t++){
      printf("In main: creating thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   pthread_exit(NULL);




}
