#ifndef _OPERATION_H
#define _OPERATION_H

typedef enum _operation
{
  UNKNOWN,
  ADDITION,
  SUBTRACTION
} OPERATION;

OPERATION getOperation(const char* equation);
const char* getOperand1(const char* equation);

#endif
