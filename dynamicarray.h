#include<math.h>
#include "structures.h"
#ifndef DYNAMICARRAY
#define DYNAMICARRAY
# ifndef TYPE
# define TYPE     int
# define TYPE_SIZE sizeof(int)
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
  int (*arraySize)(struct DynamicArray *v);
  void (*add)(struct DynamicArray *v, TYPE val);
  TYPE (*get)(struct DynamicArray *v, int pos);
  void (*put)(struct DynamicArray *v, int pos, TYPE val);
  void (*swap)(struct DynamicArray *v, int i, int  j);
  TYPE (*removeAt)(struct DynamicArray *v, int idx);
  /* Stack interface. */
  int (*isEmpty)(struct DynamicArray *v);
  void (*push)(struct DynamicArray *v, TYPE val);
  TYPE (*top)(struct DynamicArray *v);
  TYPE (*pop)(struct DynamicArray *v);
  /* Bag Interface */
  int (*contains)(struct DynamicArray *v, TYPE val);
  void (*remove)(struct DynamicArray *v, TYPE val);
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
TYPE removeAtDynArr(DynamicArray *v, int idx);
/* Stack interface. */
int isEmptyDynArr(DynamicArray *v);
void pushDynArr(DynamicArray *v, TYPE val);
TYPE topDynArr(DynamicArray *v);
TYPE popDynArr(DynamicArray *v);
/* Bag Interface */
int containsDynArr(DynamicArray *v, TYPE val);
void removeDynArr(DynamicArray *v, TYPE val);
/*-----------------------------------------------------------------------------*/

#endif // DYNAMICARRAY

