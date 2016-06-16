/*
digitextractor-tests.c
*/

#include <check.h>
#include "romanconverter.h"

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
  Suite *extraction = suite_create("Extraction");
  TCase *digitExtraction = tcase_create("DigitExtraction");
  SRunner *sr = srunner_create(extraction);

  suite_add_tcase(extraction, digitExtraction);

  tcase_add_test(digitExtraction, shouldExtractOnesDigit);
  tcase_add_test(digitExtraction, shouldExtractTensDigit);
  tcase_add_test(digitExtraction, shouldExtractHundredsDigit);
  tcase_add_test(digitExtraction, shouldExtractZeroIfNumberIsLowerThanPlace);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
