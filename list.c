/*****************************************************************************
*                                                                            *
*  -------------------------------- list.c --------------------------------  *
*                                                                            *
*****************************************************************************/

#include <stdlib.h>
#include <string.h>

#include "list.h"


List* new_list(void (*destroy)(void *data))
{

  List *list;
  list = (List*)malloc(sizeof(List));
  list->ins_next = list_ins_next;
  list->rem_next = list_rem_next;
  list->size = list_size;
  list->destroy = destroy;
  list->data = list_data;
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void delete_list(void *list) {
void               *data;

while (list_size(list) > 0) {
   if (list_rem_next(list, NULL) == 0 && ((List*)list)->destroy !=
      NULL) {
      ((List*)list)->destroy(data);
   }
}
  memset(list, 0, sizeof(List));
  return;
}

void* list_data(void* list, int number)
{
  List* lst = (List*)list;
  ListElmt * el;
  int cnt = 0;
  if (number > lst->size) {return NULL;}
  el = lst->head;
  while(cnt < number)
    {
      el = el->next;
      cnt++;
    }
  return el->data;
}

int list_size(void* list)
{
  return ((List*)list)->size;
}

int list_ins_next(void *list, ListElmt *element, const void *data) {
ListElmt           *new_element;

if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
   return -1;

new_element->data = (void *)data;
if (element == NULL) {
   if (list_size(list) == 0) {
      ((List*)list)->head = new_element;
     }
   else
     {
       ((List*)list)->tail->next = new_element;
     }
   new_element->next = NULL;
   ((List*)list)->tail = new_element;
   }
else {
   if (element->next == NULL) ((List*)list)->tail = new_element;
   new_element->next = element->next;
   element->next = new_element;
}

((List*)list)->size++;
return 0;
}


void* list_rem_next(void *list, ListElmt *element) {
ListElmt           *old_element;
void* data;

if (list_size((List*)list) == 0)
   return -1;

if (element == NULL) {

   data = ((List*)list)->head->data;
   old_element = ((List*)list)->head;
   ((List*)list)->head = ((List*)list)->head->next;
   if (list_size(((List*)list)) == 1)
      ((List*)list)->tail = NULL;
   }

else {
   if (element->next == NULL)
      return -1;
   data = element->next->data;
   old_element = element->next;
   element->next = element->next->next;
   if (element->next == NULL)
      ((List*)list)->tail = element;
}

free(old_element);
((List*)list)->size--;
return data;
}

