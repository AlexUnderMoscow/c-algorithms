
//file object1.c
#include "object1.h"
#include <stdio.h>

void method1(void)
{
   printf("obj1\n");
}
void fire1(int arg)
{
   printf("obj1 %d\n", arg);
}

obj1* new_obj1()
{
  obj1 *tmp1;
  tmp1 = (obj1*)malloc(sizeof(obj1));
  tmp1->method = method1;
  tmp1->fire = fire1;
  tmp1->some_value = 16;
  return tmp1;
}

void delete_obj1(obj1* o)
{
  o->some_value=0;
  free(o);
}

