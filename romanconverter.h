/*
  romanconverter.h
*/

#ifndef _ROMANCONVERTER_H
#define _ROMANCONVERTER_H

int toRoman(char *numeral, int number);
int toNumber(int *number, const char* numeral);
int extractDigit(int number, int place);
int findPatternInString(const char* string, const char *patterns[]);

#endif
