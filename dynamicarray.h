#include<math.h>
#include "structures.h"
#ifndef DYNAMICARRAY
#define DYNAMICARRAY
# ifndef TYPE
# define TYPE     my
# define TYPE_SIZE sizeof(my)
# endif

# ifndef EQ
# define EQ(A, B) (fabs(A - B) < 10e-7)
# endif

//typedef struct DynArr DynArr;
typedef struct DynamicArray {
  TYPE *data;		/* pointer to the data array */
  int size;		/* Number of elements in the array */
  int capacity;         /* capacity ofthe array */
  /* Dynamic Array Functions */
  int (*arraySize)(void *v);
  void (*add)(void *v, TYPE val);
  TYPE (*get)(void *v, int pos);
  void (*put)(void *v, int pos, TYPE val);
  void (*swap)(void *v, int i, int  j);
  void (*removeAt)(void *v, int idx);
  /* Stack interface. */
  int (*isEmpty)(void *v);
  void (*push)(void *v, TYPE val);
  TYPE (*top)(void *v);
  void (*pop)(void *v);
  /* Bag Interface */
  int (*contains)(void *v, TYPE val);
  void (*remove)(void *v, TYPE val);
} DynamicArray;
//*  --------------------------- Public Interface ---------------------------  *
/* Dynamic Array Functions */
DynamicArray *new_DynamicArray(int cap);
void delete_DynamicArray(DynamicArray *v);

int sizeDynArr(DynamicArray *v);
void addDynArr(DynamicArray *v, TYPE val);
TYPE getDynArr(DynamicArray *v, int pos);
void putDynArr(DynamicArray *v, int pos, TYPE val);
void swapDynArr(DynamicArray *v, int i, int  j);
void removeAtDynArr(DynamicArray *v, int idx);
/* Stack interface. */
int isEmptyDynArr(DynamicArray *v);
void pushDynArr(DynamicArray *v, TYPE val);
TYPE topDynArr(DynamicArray *v);
void popDynArr(DynamicArray *v);
/* Bag Interface */
int containsDynArr(DynamicArray *v, TYPE val);
void removeDynArr(DynamicArray *v, TYPE val);
/*-----------------------------------------------------------------------------*/

#endif // DYNAMICARRAY

