#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "list.h"
#include "stack.h"
#include "dynamicarray.h"
#include "expressionsolver.h"
#include "mergesort.h"
#include "bubble.h"
#include "heapsort.h"
#include "quicksort.h"
#include "selection.h"
#include "linkedlist.h"

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
  int size;
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
/*-----------------heapsort--------------------------*/
  //int arr[]={29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
  //int arr[]={27,28,29,24,25,26,21,22,23,18,20,16,17,18,13,14,15,10,11,12,7,8,9,4,5,6,1,2,3};
  int arr[]={2,7,1,3,5,6,4};
  quickSort(arr,7);
  //heapSort(arr,29);
/*-----------------mergesort-------------------------*/

 // mergesortBU(arr,0,8);
  //mergeSortAlex(arr,29);
/*---------------bubble-----------------------------*/
  //bubble(arr,29);
/*----------selection-------------------------------*/
  //selection(arr,29);
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
/*-----------LinkedList-------------*/
  LinkedList* list = new_LinkedList();
  for (int step = 0; step< 1024*1024*10; step++)
 {
  list->add(list,1);
  list->add(list,2);
  list->add(list,3);
  list->add(list,4);
  list->add(list,5);

  list->addBack(list,0);
  list->addFront(list,6);

  int val = 3;
  //if (list->contains(list,val))
//    printf("list contains %d\n", val);
//  else
//    printf("list not contains %d\n",val);

  int back = list->back(list);
  int front = list->front(list);

//  if (list->isEmpty(list))
//    printf("list is empty\n");
//  else
//    printf("list is not empty\n");

  list->removeBack(list);
  list->removeFront(list);
  size = list->size(list);

  list->remove(list,0);
  list->remove(list,3);
  list->remove(list,2);
  list->remove(list,1);
  list->remove(list,0);
  size = list->size(list);
}
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

  size = lst->size;
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
