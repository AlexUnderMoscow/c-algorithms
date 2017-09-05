#ifndef EXPRESSIONSOLVER
#define EXPRESSIONSOLVER

#include "dynamicarray.h"

typedef struct ExpressionSolver {
  DynamicArray* da;
  double (*postfixCalc)(void* es, char* input);
  void (*postfixTransform)(void* es, char* input, char* output);
} ExpressionSolver;

ExpressionSolver* new_expressionsolver(int size);
void delete_expressionsolver(ExpressionSolver* es);
double expressionsolver_postfixCalc(ExpressionSolver* es, char* input);
void expressionsolver_postfixTransform(ExpressionSolver* es ,char* input, char* output);

#endif // EXPRESSIONSOLVER


