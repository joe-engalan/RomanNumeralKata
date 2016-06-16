/*
  toroman.c
*/
#include <stdio.h>

static const char* ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

int extractDigit(int number, int place)
{
  return (number % (10 * place)) / place;
}

int toRoman(char* numeral, int number)
{
  int onesDigit = extractDigit(number, 1);
  sprintf(numeral, "%s", ones[onesDigit]);
  return 1;
}
