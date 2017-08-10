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
  stack->push = stack_push;
  stack->pop = stack_pop;
  stack->size = stack_size;
  stack->destroy = destroy;
  stack->sizeofstack = 0;
  stack->head = NULL;
  return stack;
}

void delete_stack(void *stack) {
void               *data;

while (stack_size(stack) > 0) {
   if (list_rem_next(stack, NULL) == 0 && ((Stack*)stack)->destroy !=
      NULL) {
      ((Stack*)stack)->destroy(data);
   }
}
  memset(stack, 0, sizeof(Stack));
  return;
}

int stack_size(void *stack)
{
    return ((Stack*)stack)->sizeofstack;
}

/*добавление элемента в стек*/
int stack_push(void *stack, void *data)
{
    StackElmt *new_element;
    if ((new_element = (StackElmt *)malloc(sizeof(StackElmt))) == NULL)
       return -1;
/*если элементов еще не было*/
    if (((Stack*)stack)->sizeofstack == 0)
      {
        new_element->next=NULL;
      } /*иначе если что то было уже*/
    else
      {
        new_element->next = ((Stack*)stack)->head;
      }
      ((Stack*)stack)->head = new_element;
      ((Stack*)stack)->sizeofstack++;
      new_element->data = data;

    return 0;
}

void* stack_pop(void *stack)
{
    if (((Stack*)stack)->sizeofstack==0)
    {
      return NULL;
    }
    StackElmt *deletingElement;
    void *result;
    deletingElement = ((Stack*)stack)->head;
    result = deletingElement->data;
    ((Stack*)stack)->head=deletingElement->next;
    ((Stack*)stack)->sizeofstack--;
    free(deletingElement);
    if (((Stack*)stack)->sizeofstack==0)
      {
        ((Stack*)stack)->head = NULL;
      }
    return result;

}

