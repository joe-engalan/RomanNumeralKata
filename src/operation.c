/*
operation.c
*/

#include "operation.h"

OPERATION getOperation(const char* equation)
{
  if(strstr(equation, "+"))
  {
    return ADDITION;
  }

  if(strstr(equation, "-"))
  {
    return SUBTRACTION;
  }

  return UNKNOWN;
}
