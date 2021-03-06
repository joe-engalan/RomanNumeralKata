#ifndef _OPERATION_H
#define _OPERATION_H

typedef enum _operation
{
  UNKNOWN,
  ADDITION,
  SUBTRACTION
} OPERATION;

OPERATION getOperation(const char* equation);
int getOperands(char* operands[], char* equation);

#endif
