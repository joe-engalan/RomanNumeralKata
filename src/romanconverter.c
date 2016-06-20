/*
  romanconverter.c
*/
#include <stdio.h>
#include <string.h>

static const char* ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
static const char* tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
static const char* hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
static const char* thousands[] = { "", "M", "MM", "MMM" };

int extractDigit(int number, int place)
{
  return (number % (10 * place)) / place;
}

int findPatternInString(const char *string, int numPatterns, const char *patterns[])
{
  for(int i = numPatterns - 1; i >= 0; --i)
  {
    if(strstr(string, patterns[i]))
    {
//      printf("pattern \"%s\" found in \"%s\" at %d\n", patterns[i], string, i);
      return i;
    }
  }

  return -1;
}

int findPatternInRomanNumeralString(const char* string, int numPatterns, const char* patterns[])
{
  // Roman numeral pattern matching gets tricky around the 5
  // because 4 might also match (eg. "CD" matches "D" and "CD")
  // If the regular pattern matches 5, also check 4 to see if it's
  // a match. Return the 4 since it matches more characters
  int matchedPattern = findPatternInString(string, numPatterns, patterns);
  if(matchedPattern == 5)
  {
    int alternateMatch = findPatternInString(string, 5, patterns);
    if(alternateMatch > 0)
    {
      matchedPattern = alternateMatch;
    }
  }

  return matchedPattern;
}

int toRoman(char* numeral, int number)
{
  if(number < 0 || number > 3999)
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

int toNumber(int *number, const char *numeral)
{
  int thousandsDigit = findPatternInRomanNumeralString(numeral, 4, thousands);
  int hundredsDigit = findPatternInRomanNumeralString(numeral, 10, hundreds);
  int tensDigit = findPatternInRomanNumeralString(numeral, 10, tens);
  int onesDigit = findPatternInRomanNumeralString(numeral, 10, ones);

  *number = (thousandsDigit * 1000) + (hundredsDigit * 100) + (tensDigit * 10) + onesDigit;

  return 1;
}
