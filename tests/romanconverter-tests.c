/*
romanconverter-tests.c
*/

#include <check.h>
#include "romanconverter.h"

char numeral[20];
int number;

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

START_TEST(shouldReturnBlankIfNumberIsLessThan0)
{
  int status = toRoman(numeral, -1);

  ck_assert_str_eq(numeral, "");
  ck_assert_int_eq(status, 0);
}
END_TEST

/* TO NUMBER TESTS */
START_TEST(shouldDecipherThousandsPlace)
{
    toNumber(&number, "MMM");

    ck_assert_int_eq(number, 3000);
}
END_TEST

START_TEST(shouldDeciperHundredsPlace)
{
  toNumber(&number, "CD");

  ck_assert_int_eq(number, 400);

}
END_TEST

START_TEST(shouldDecipherAllPlaces)
{
  toNumber(&number, "MCCXLVIII");

  ck_assert_int_eq(number, 1248);

}
END_TEST

START_TEST(shouldDecipherWithMissingPlaces)
{
  toNumber(&number, "CDV");

  ck_assert_int_eq(number, 405);
}
END_TEST

START_TEST(shouldRecognizeInvalidNumber)
{
  int status = toNumber(&number, "abc");

  ck_assert_int_eq(status, 0);
}
END_TEST

int main(void)
{
  Suite *romanConversion = suite_create("RomanConversion");
  TCase *toRoman = tcase_create("ToRoman");
  TCase *toNumber = tcase_create("ToNumber");
  SRunner *sr = srunner_create(romanConversion);

  suite_add_tcase(romanConversion, toRoman);
  suite_add_tcase(romanConversion, toNumber);

  tcase_add_test(toRoman, shouldConvert5);
  tcase_add_test(toRoman, shouldConvert9);
  tcase_add_test(toRoman, shouldConvertTensPlace);
  tcase_add_test(toRoman, shouldInsertBlankForZeroDigits);
  tcase_add_test(toRoman, shouldReturnBlankIfNumberIsGreaterThan3999);
  tcase_add_test(toRoman, shouldReturnBlankIfNumberIsLessThan0);

  tcase_add_test(toNumber, shouldDecipherThousandsPlace);
  tcase_add_test(toNumber, shouldDeciperHundredsPlace);
  tcase_add_test(toNumber, shouldDecipherAllPlaces);
  tcase_add_test(toNumber, shouldDecipherWithMissingPlaces);

  tcase_add_test(toNumber, shouldRecognizeInvalidNumber);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
