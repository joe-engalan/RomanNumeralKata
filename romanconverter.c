/*
  romanconverter.c
*/
#include <stdio.h>

static const char* ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
static const char* tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
static const char* hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
static const char* thousands[] = { "", "M", "MM", "MMM" };

int extractDigit(int number, int place)
{
  return (number % (10 * place)) / place;
}

int toRoman(char* numeral, int number)
{
  if(number > 3999)
  {
    numeral[0] = 0;
    return 0;
  }

  int onesDigit = extractDigit(number, 1);
  int tensDigit = extractDigit(number, 10);
  int hundredsDigit = extractDigit(number, 100);
  int thousandsDigit = extractDigit(number, 1000);

  sprintf(numeral, "%s%s%s%s", thousands[thousandsDigit], hundreds[hundredsDigit], tens[tensDigit], ones[onesDigit]);
  return 1;
}
