#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include "list.h"

/*****************************************************************************
*                                                                            *
*  Implement stacks as linked lists.                                         *
*                                                                            *
*****************************************************************************/

//*  ЭЛЕМЕНТ СТЭКА                        *

typedef struct StackElmt_ {
void               *data;
struct StackElmt_   *next;
} StackElmt;

//* САМ СТЭК                                 *

typedef struct Stack {
int               stack_size;
int               (*push)(void *stack, void *element);
void*             (*pop)(void *stack);
int               (*size)(void * stack);
//void              (*destroy)(void *data);
ListElmt           *head;
} Stack;

/*****************************************************************************
*                                                                            *
*  --------------------------- Public Interface ---------------------------  *
*                                                                            *
*****************************************************************************/
//The stack_init operation initializes a stack so that it can be used in other operations
//Since a stack is a linked list and requires the same initialization, stack_init is defined to list_init.

Stack*      new_stack(void (*destroy)(void *data));
void        delete_stack(void* stack);
int         stack_size(void * stack);
int         stack_push(void *stack, void *element);
void*       stack_pop(void *stack);

#endif // STACK_H

