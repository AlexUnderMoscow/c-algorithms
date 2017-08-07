
//file object2.c
#include "object2.h"
#include <stdio.h>


void method2(void)
{
  printf("obj2\n");
}
void fire2(int arg)
{
  printf("obj2 %d \n",arg);
}

obj2* new_obj2()
{
  obj2 *tmp2;
  tmp2 = (obj2*)malloc(sizeof(obj2));
  tmp2->method = method2;
  tmp2->fire = fire2;
  tmp2->some_value = 26;
  return tmp2;
}

void delete_obj2(obj2* o)
{
  o->some_value=0;
  free(o);
}

//bool char short int long float double
//структуры данных                    typedef struct
//динамическая память                 malloc free
//доступ к членам структуры           s.var s->var
//указатель на функцию                void (*fire)(int);
