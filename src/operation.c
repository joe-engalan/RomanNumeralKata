/*
operation.c
*/

#include <string.h>
#include <stdlib.h>
#include "operation.h"
#include "trim.h"

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

int getOperands(char* operands[], char* equation)
{
  const char* operations = "+-";

  printf("equation: %0x, \"%s\"\n", equation, equation);

  char* operand = trim(strtok(equation, operations));

  printf("Operand: %0x, \"%s\"\n", operand, operand);
  if(operand == 0 || strlen(operand) == 0)
  {
    return 0;
  }

  operands[0] = operand;
  operand = strtok(0, operations);
  if(operand == 0 || strlen(operand) == 0)
  {
    return 1;
  }

  operands[1] = trim(operand);
  return 2;
}
