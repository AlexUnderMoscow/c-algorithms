/*****************************************************************************
*                                                                            *
*  ------------------------------- stack.c --------------------------------  *
*                                                                            *
*****************************************************************************/

#include <stdlib.h>

#include "list.h"
#include "stack.h"

/*
 * typedef struct StackElmt_ {
void               *data;
struct StackElmt_   *next;
} StackElmt;

//* САМ СТЭК                                 *

typedef struct Stack {
int               sizeofstack;
int               (*push)(void *stack, void *element);
void*             (*pop)(void *stack);
int               (*size)(void * stack);
//void              (*destroy)(void *data);
ListElmt           *head;
} Stack;

Stack*      new_stack(void (*destroy)(void *data));
void        delete_stack(void* stack);
int         stack_size(void * stack);
int         stack_push(void *stack, void *element);
void*       stack_pop(void *stack);
*/
Stack* new_stack(void (*destroy)(void *data))
{

  Stack *stack;
  stack = (Stack*)malloc(sizeof(Stack));
  stack->stack_push = push;
  stack->stack_pop = pop;
  stack->stack_size = size;

  stack->sizeofstack = 0;
  stack->head = NULL;
  return list;
}

