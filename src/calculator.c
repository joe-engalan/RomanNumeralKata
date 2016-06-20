/*
calculator.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "calculator.h"
#include "operation.h"
#include "romanconverter.h"


STATUS_TYPE getOperandsFromEquation(int *operands, const char* equation)
{
  if(getOperation(equation) == UNKNOWN)
  {
    return ERROR_OPERATION;
  }

  char *operandStrings[2];
  char *tmpEquation = strdup(equation);
  int numOperands = getOperands(operandStrings, tmpEquation);
  if(numOperands != 2)
  {
    free(tmpEquation);
    return ERROR_INSUFFICIENT_OPPERANDS;
  }

  if(toNumber(&operands[0], operandStrings[0]) == 0)
  {
    free(tmpEquation);
    return ERROR_INVALID_OPERAND;
  }

  if(toNumber(&operands[1], operandStrings[1]) == 0)
  {
    free(tmpEquation);
    return ERROR_INVALID_OPERAND;
  }
  
  free(tmpEquation);
  return STATUS_OK;
}

int performOperation(OPERATION op, int operand1, int operand2)
{
  int numberResult = 0;
  if(op == SUBTRACTION)
  {
    // printf("Subtracting %d-%d\n", operand1, operand2);
    numberResult = operand1 - operand2;
  }
  else if(op = ADDITION)
  {
    // printf("Adding %d+%d\n", operand1, operand2);
    numberResult = operand1 + operand2;
  }
  return numberResult;
}

STATUS_TYPE validateResult(int result)
{
  STATUS_TYPE status = STATUS_OK;
    if(result < 0)
    {
      status = ERROR_UNDERFLOW;
    }
    else if(result > 3999)
    {
      status = ERROR_OVERFLOW;
    }

    return status;
}

STATUS_TYPE calculate(char* result, const char* equation)
{
  int operands[2];
  int numberResult = 0;

  STATUS_TYPE status = getOperandsFromEquation(operands, equation);
  if(status != STATUS_OK)
  {
    return status;
  }

  OPERATION op = getOperation(equation);
  numberResult = performOperation(op, operands[0], operands[1]);
  status = validateResult(numberResult);
  if(status != STATUS_OK)
  {
    return status;
  }

  toRoman(result, numberResult);
  return status;
}
