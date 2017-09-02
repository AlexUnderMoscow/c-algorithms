/*****************************************************************************
*                                                                            *
*  ------------------------------- stack.c --------------------------------  *
*                                                                            *
*****************************************************************************/

#include <stdlib.h>

#include "list.h"
#include "stack.h"


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

void* stack_rem_next(void *stack, StackElmt *element) {
ListElmt           *old_element;
void* data;

if (stack_size((Stack*)stack) == 0)
   return -1;

if (element == NULL) {

   data = ((Stack*)stack)->head->data;
   old_element = ((Stack*)stack)->head;
   ((Stack*)stack)->head = ((Stack*)stack)->head->next;
   }

else {
   if (element->next == NULL)
      return -1;
   data = element->next->data;
   old_element = element->next;
   element->next = element->next->next;

}

free(old_element);
((Stack*)stack)->size--;
return data;
}



void delete_stack(void *stack)
{
void               *data;

while (stack_size(stack) > 0) {
   if (stack_rem_next(stack, NULL) == 0 && ((Stack*)stack)->destroy !=
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
