#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "object1.h"
#include "object2.h"
#include "list.h"

#define NUM_THREADS     5

typedef struct my_{
  int count;
  char c;
} my;

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
/*----------------------------------*/

  int rc;
  long t;
  int temp1 = 444;
  int temp2 = 888;
  pthread_t threads[NUM_THREADS];

  obj1 *o1, *o11;
  obj2 *o2;
  o1 = new_obj1();
  o2 = new_obj2();
  o1->fire(111);
  o2->fire(222);

  pthread_create(&threads[0],NULL,o1->fire,(void*)temp1);
  pthread_create(&threads[1],NULL,o2->fire,(void*)temp2);
  pthread_join(threads[0],NULL);
  pthread_join(threads[1],NULL);

    printf("Value1=%d \n",o1->some_value);
    printf("Value2=%d \n",o2->some_value);

  //free(o1); o1=NULL;
  delete_obj1(o1); o1=NULL;
  delete_obj2(o2); o2=NULL;

   for(t=0; t<NUM_THREADS; t++){
      printf("In main: creating thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   /* Last thing that main() should do */
   pthread_exit(NULL);




}
