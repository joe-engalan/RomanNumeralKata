/*
toroman-tests.c
*/

#include <check.h>
#include "toroman.h"

char numeral[20];

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

START_TEST(shouldExtractOnesDigit)
{
  int onesDigit = extractDigit(19, 1);

  ck_assert_int_eq(onesDigit, 9);
  ck_assert_int_eq(extractDigit(9, 1), 9);
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
  tcase_add_test(digitExtraction, shouldExtractOnesDigit);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
