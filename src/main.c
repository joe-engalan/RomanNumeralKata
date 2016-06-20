/* main.c
*/
#include <stdio.h>
#include <string.h>
#include "calculator.h"

const char* getError(STATUS_TYPE status)
{
  if(status == STATUS_OK) return "OK.";
  else if(status == ERROR_OPERATION) return "Invalid operation.";
  else if(status == ERROR_INSUFFICIENT_OPPERANDS) return "Insufficient operands.";
  else if(status == ERROR_UNDERFLOW) return "Invalid result less than 0.";
  else if(status == ERROR_OVERFLOW) return "Invalid result more than 3999.";
  else return "Unknown status.";
}

void main(int argc, char** argv)
{
  printf("Welcome to the roman numeral calculator!\n");
  printf("It can calculate addition and subtraction in roman numerals.\n");
  printf("e.g.:\n");
  printf("\tMM + M = MMM\n");
  printf("\tIII - I = II\n");
  printf("\n");

  char equation[80];
  char answer[20];
  while(1)
  {
    printf("Enter an equation: ");
    char* result = fgets(equation, 80, stdin);
    if(result == 0 || strlen(equation) == 0)
    {
      break;
    }

    STATUS_TYPE status = calculate(answer, equation);
    if(status != STATUS_OK)
    {
      printf("Error: %s\n", getError(status));
    }
    else
    {
      printf("%s\n", answer);
    }
  }

  printf("Goodbye.\n");
}
