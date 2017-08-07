
/*****************************************************************************
*                                                                            *
*  -------------------------------- list.h --------------------------------  *
*                                                                            *
*****************************************************************************/

#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

//*  ЭЛЕМЕНТ СПИСКА                        *

typedef struct ListElmt_ {
void               *data;
struct ListElmt_   *next;
} ListElmt;

 //* САМ СПИСОК                                 *

typedef struct List {
int               size;
int               (*ins_next)(void *list, ListElmt *element, const void *data);
void*             (*rem_next)(void *list, ListElmt *element);
void              (*destroy)(void *data);
void*             (*data)(void* list, int number);
ListElmt           *head;
ListElmt           *tail;
} List;

//*  --------------------------- Public Interface ---------------------------  *
int         list_ins_next(void *list, ListElmt *element, const void *data);
void*         list_rem_next(void *list, ListElmt *element);
//ListElmt*   list_head(List* list);
//ListElmt*   list_tail(List* list);
int         list_size(void* list);
void*       list_data(void* list, int number);
//ListElmt    list_next(ListElmt* element);
List*       new_list(void (*destroy)(void *data));
void        delete_list(void* list);
/*-----------------------------------------------------------------------------*/




#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
//#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)


#endif // LIST_H

