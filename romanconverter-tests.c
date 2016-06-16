/*
romanconverter-tests.c
*/

#include <check.h>
#include "romanconverter.h"

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

int main(void)
{
  Suite *romanConversion = suite_create("RomanConversion");
  TCase *toRoman = tcase_create("ToRoman");
  SRunner *sr = srunner_create(romanConversion);

  suite_add_tcase(romanConversion, toRoman);

  tcase_add_test(toRoman, shouldConvert5);
  tcase_add_test(toRoman, shouldConvert9);
  tcase_add_test(toRoman, shouldConvertTensPlace);
  tcase_add_test(toRoman, shouldInsertBlankForZeroDigits);
  tcase_add_test(toRoman, shouldReturnBlankIfNumberIsGreaterThan3999);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
