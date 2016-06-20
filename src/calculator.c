/*
calculator.c
*/

#include <stdlib.h>
#include <string.h>
#include "calculator.h"
#include "operation.h"


STATUS_TYPE getOperandsFromEquation(int *operands, char* equation)
{
  if(getOperation(equation) == UNKNOWN)
  {
    return ERROR_OPERATION;
  }

  char *operandStrings[2];
  int numOperands = getOperands(operandStrings, equation);
  if(numOperands != 2)
  {
    return ERROR_INSUFFICIENT_OPPERANDS;
  }

  toNumber(&operands[0], operandStrings[0]);
  toNumber(&operands[1], operandStrings[1]);
  return STATUS_OK;
}

STATUS_TYPE calculate(char* result, const char* equation)
{
  char *tmpEquation = strdup(equation);
  int operands[2];
  int numberResult = 0;

  STATUS_TYPE status = getOperandsFromEquation(operands, tmpEquation);
  if(status == STATUS_OK)
  {
    OPERATION op = getOperation(equation);
    if(op == SUBTRACTION)
    {
      printf("Subtracting %d-%d\n", operands[0], operands[1]);
      numberResult = operands[0] - operands[1];
    }
    else if(op = ADDITION)
    {
      printf("Adding %d+%d\n", operands[0], operands[1]);
      numberResult = operands[0] + operands[1];
    }

  }

  if(numberResult < 0)
  {
    status = ERROR_UNDERFLOW;
  }
  else if(numberResult > 3999)
  {
    status = ERROR_OVERFLOW;
  }

  free(tmpEquation);
  return status;
}
