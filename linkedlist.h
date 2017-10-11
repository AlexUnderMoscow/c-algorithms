#ifndef LINKEDLIST_H
#define LINKEDLIST_H
# ifndef TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif
# ifndef LT
# define LT(A, B) ((A) < (B))
# endif

# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

/* Double Link*/
struct DLink{
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

typedef struct LinkedList{
	int sizeoflist;
	struct DLink *firstLink;
	struct DLink *lastLink;
	/* Deque Interface */
	int 	(*size)(struct LinkedList *lst);
	int 	(*isEmpty)(struct LinkedList *lst);
	void	(*addBack)(struct LinkedList *lst, TYPE e);
	void 	(*addFront)(struct LinkedList *lst, TYPE e);
	TYPE	(*front)(struct LinkedList *lst);
	TYPE 	(*back)(struct LinkedList *lst);
	TYPE 	(*at)(struct LinkedList *lst, int pos);
	void	(*removeFront)(struct LinkedList *lst);
	void 	(*removeBack)(struct LinkedList *lst);
	/*Bag Interface */
	void	(*add)(struct LinkedList *lst, TYPE v);
	int	(*contains)(struct LinkedList *lst, TYPE e);
	void	(*remove)(struct LinkedList *lst, int pos);
}LinkedList;

//struct linkedList;

LinkedList *new_LinkedList();
void delete_LinkedList(struct LinkedList *lst);

/* Deque Interface */
int 	isEmptyList(struct LinkedList *lst);
int 	sizeList(struct LinkedList *lst);
void	addBackList(struct LinkedList *lst, TYPE e);
void 	addFrontList(struct LinkedList *lst, TYPE e);
TYPE	frontList(struct LinkedList *lst);
TYPE 	backList(struct LinkedList *lst);
TYPE 	atList(struct LinkedList *lst, int pos);
void	removeFrontList(struct LinkedList *lst);
void 	removeBackList(struct LinkedList *lst);
/*Bag Interface */
void	addList(struct LinkedList *lst, TYPE v);
int	containsList(struct LinkedList *lst, TYPE e);
void	removeList(struct LinkedList *lst, int pos);
#endif // LINKEDLIST_H

