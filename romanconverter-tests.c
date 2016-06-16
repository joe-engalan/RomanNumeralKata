/*
toroman-tests.c
*/

#include <check.h>
#include "toroman.h"

char numeral[20];

/* TO ROMAN TESTS */

START_TEST(shouldConvert5)
{
  toRoman(numeral, 5);

  ck_assert_str_eq(numeral, "V");
}
END_TEST

START_TEST(shouldConvert9)
{
  toRoman(numeral, 9);

  ck_assert_str_eq(numeral, "IX");
}
END_TEST

START_TEST(shouldConvertTensPlace)
{
  toRoman(numeral, 56);

  ck_assert_str_eq(numeral, "LVI");
}
END_TEST

START_TEST(shouldInsertBlankForZeroDigits)
{
  toRoman(numeral, 2007);

  ck_assert_str_eq(numeral, "MMVII");
}
END_TEST

START_TEST(shouldReturnBlankIfNumberIsGreaterThan3999)
{
  int status = toRoman(numeral, 100000);

  ck_assert_str_eq(numeral, "");
  ck_assert_int_eq(status, 0);
}
END_TEST

/* EXTRACTION TESTS */

START_TEST(shouldExtractOnesDigit)
{
  int onesDigit = extractDigit(19, 1);

  ck_assert_int_eq(onesDigit, 9);
}
END_TEST

START_TEST(shouldExtractTensDigit)
{
  int tensDigit = extractDigit(761, 10);

  ck_assert_int_eq(tensDigit, 6);
}
END_TEST

START_TEST(shouldExtractHundredsDigit)
{
  int hundredsDigit = extractDigit(1234, 100);

  ck_assert_int_eq(hundredsDigit, 2);
}
END_TEST

START_TEST(shouldExtractZeroIfNumberIsLowerThanPlace)
{
  int thouseandsDigit = extractDigit(1, 1000);

  ck_assert_int_eq(thouseandsDigit, 0);
}
END_TEST

int main(void)
{
  Suite *romanConversion = suite_create("RomanConversion");
  TCase *toRoman = tcase_create("ToRoman");
  TCase *digitExtraction = tcase_create("DigitExtraction");
  SRunner *sr = srunner_create(romanConversion);

  suite_add_tcase(romanConversion, toRoman);
  suite_add_tcase(romanConversion, digitExtraction);

  tcase_add_test(toRoman, shouldConvert5);
  tcase_add_test(toRoman, shouldConvert9);
  tcase_add_test(toRoman, shouldConvertTensPlace);
  tcase_add_test(toRoman, shouldInsertBlankForZeroDigits);
  tcase_add_test(toRoman, shouldReturnBlankIfNumberIsGreaterThan3999);

  tcase_add_test(digitExtraction, shouldExtractOnesDigit);
  tcase_add_test(digitExtraction, shouldExtractTensDigit);
  tcase_add_test(digitExtraction, shouldExtractHundredsDigit);
  tcase_add_test(digitExtraction, shouldExtractZeroIfNumberIsLowerThanPlace);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
