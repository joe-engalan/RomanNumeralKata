/*
trim.c
*/

#include <string.h>
#include <ctype.h>

char* trimLeading(char* str)
{
  char* current = str;

  while(isspace(*current))
  {
    current++;
  }

  return current;
}

char* trimTrailing(char *str)
{
  char* current = str + strlen(str) - 1;

  while(current > str && isspace(*current))
  {
    --current;
  }

  ++current;
  *current = 0;

  return str;
}

char* trim(char* str)
{
  char* trimmed = trimLeading(str);
  trimmed = trimTrailing(trimmed);

  return trimmed;
}
