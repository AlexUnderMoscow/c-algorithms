#include "expressionsolver.h"



ExpressionSolver* new_expressionsolver(int size)
{
  ExpressionSolver* es=(ExpressionSolver*)malloc(sizeof(ExpressionSolver));
  es->da = new_DynamicArray(size);
  es->postfixCalc = expressionsolver_postfixCalc;
   es->postfixTransform = expressionsolver_postfixTransform;
  return es;
}

double expressionsolver_postfixCalc(ExpressionSolver* es, char* input)
{
  int a,b;
  char digit[2];
  digit[1]=0;
  for (int i=0; i<strlen(input); i++)
    {
      if (input[i]=='+')
        {
          a = es->da->pop(es->da);
          b = es->da->pop(es->da);
          es->da->push(es->da,a+b);
        }
      if (input[i]=='*')
        {
          a = es->da->pop(es->da);
          b = es->da->pop(es->da);
          es->da->push(es->da,a*b);
        }
      if ((input[i]>='0') && (input[i]<='9'))
        {
          digit[0]=input[i];
          es->da->push(es->da,atoi(&digit));
        }

    }
  double res = es->da->pop(es->da);
  return res;
}

void expressionsolver_postfixTransform(ExpressionSolver* es, char* input, char* output)
{
  int index = 0;
  for (int i=0; i<strlen(input); i++)
    {
      if (input[i]==')')
      output[index++] = es->da->pop(es->da);

      if ((input[i]=='+') || (input[i]=='*'))
        es->da->push(es->da,input[i]);

      if ((input[i]>='0') && (input[i]<='9'))
         output[index++] = input[i];

    }
  output[index] = 0;
  return;
}

void delete_expressionsolver(ExpressionSolver* es)
{
  free (es->da);
  free (es);
}
