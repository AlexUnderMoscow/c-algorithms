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
int               sizeofstack;
int               (*push)(void *stack, void *data);
void*             (*pop)(void *stack);
int               (*size)(void * stack);
void              (*destroy)(void *data);
StackElmt           *head;
} Stack;

/*****************************************************************************
*                                                                            *
*  --------------------------- Public Interface ---------------------------  *
*                                                                            *
*****************************************************************************/
Stack*      new_stack(void (*destroy)(void *data));
void        delete_stack(void* stack);
int         stack_size(void * stack);
int         stack_push(void *stack, void *data);
void*       stack_pop(void *stack);

#endif // STACK_H

