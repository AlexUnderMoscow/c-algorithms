#include "linkedlist.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (LinkedList *lst){
	lst->firstLink = malloc(sizeof(struct DLink));
	assert(lst->firstLink != 0);
	lst->lastLink = malloc(sizeof(struct DLink));
	assert(lst->lastLink);
	lst->firstLink->next = lst->lastLink;
	lst->lastLink->prev = lst->firstLink;
	lst->sizeoflist = 0;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

LinkedList *new_LinkedList(){

	LinkedList *newList = (LinkedList*)malloc(sizeof(LinkedList));
	newList->add = addList;
	newList->addBack = addBackList;
	newList->addFront = addFrontList;
	newList->back = backList;
	newList->contains=containsList;
	newList->front = frontList;
	newList->isEmpty = isEmptyList;
	newList->remove = removeList;
	newList->removeBack = removeBackList;
	newList->removeFront = removeFrontList;
	newList->size = sizeList;
	newList->at= atList;
	_initList(newList);
	return(newList);
}

int 	sizeList(LinkedList *lst)
{
    return lst->sizeoflist;
}

void delete_LinkedList(struct LinkedList *lst)
{
    while(!lst->isEmpty(lst))
      lst->removeFront(lst);
    free (lst);
    return;
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(LinkedList *lst, struct DLink *l, TYPE v){
	struct DLink *prevLink = l->prev;
	struct DLink *newLink = (struct DLink *) malloc(sizeof(struct DLink));

	assert(lst);
	/*assign newLink attributes*/
	newLink->value = v;
	newLink->next = l;
	newLink->prev = prevLink;

	/*reassign lnk and previousLink attributes*/
	l->prev = newLink;
	prevLink->next = newLink;

	lst->sizeoflist++;
}

/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(LinkedList *lst, TYPE e){
	assert(lst);
	_addLinkBefore(lst, lst->firstLink->next, e);
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(LinkedList *lst, TYPE e){
	assert(lst);
	_addLinkBefore(lst, lst->lastLink, e);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (LinkedList *lst){
	assert(lst);
	assert(lst->sizeoflist > 0);

    return lst->firstLink->next->value;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(LinkedList *lst){
	assert(lst);
	assert(lst->sizeoflist > 0);

    return lst->lastLink->prev->value;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(LinkedList *lst, struct DLink *l){
    struct DLink *prevLink = l->prev;
    struct DLink *nextLink = l->next;

    assert(lst);

    prevLink->next = nextLink;
    nextLink->prev = prevLink;

    free(l);
    lst->sizeoflist--;
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(LinkedList *lst){
	assert(lst);
	assert(! isEmptyList(lst));
	_removeLink (lst, lst->firstLink->next);
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(LinkedList *lst){
	assert(lst);
	assert(! isEmptyList(lst));
	_removeLink (lst, lst->lastLink->prev);
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(LinkedList *lst){
	assert(lst);
	return lst->sizeoflist == 0;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(LinkedList* lst){
        struct DLink * current = lst->firstLink;

	assert(lst->firstLink);
	while(current->next != lst->lastLink){
		current = current->next;
		printf("%d\n", current->value);
	}
}

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(LinkedList *lst, TYPE v){
	assert(lst);
	addFrontList(lst, v);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0
	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (LinkedList *lst, TYPE e){
        struct DLink *current = lst->firstLink;
        int pos = 0;
        assert(lst);
    assert(! isEmptyList(lst));
        while(current->next != lst->lastLink)
        {
                  current = current->next;
          if(current->value == e)
                        return pos;
          pos++;
        }

        return -1;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs
	param:	lst		pointer to the bag
	param:	pos		position to be removed
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (LinkedList *lst, int pos){
        struct DLink *current = lst->firstLink; //firstLink->next
    int index = 0;
    assert(lst);
    assert(! isEmptyList(lst));
        while(current->next != lst->lastLink){
        current = current->next;
        if(pos == index) {
            _removeLink(lst, current);
            return;
        }
        index++;

    }

    return;
}

TYPE atList(LinkedList *lst, int pos)
{
  struct DLink *current = lst->firstLink; //firstLink->next
int index = 0;
if (pos+1 > lst->sizeoflist)
  return 0;
assert(lst);
assert(! isEmptyList(lst));
  while(current->next != lst->lastLink){
  current = current->next;
  if(pos == index) {
      return current->value;
  }
  index++;

}

}
