/*
trim-tests.c
*/

#include <check.h>
#include "trim.h"

START_TEST(shouldTrimLeadingWhitespace)
{
  char str[80];
  strcpy(str, "   test");

  char *actual = trim(str);
  ck_assert_str_eq(actual, "test");
}
END_TEST

START_TEST(shouldTrimTrailingWhitespace)
{
  char str[80];
  strcpy(str, "test      ");

  char *actual = trim(str);
  ck_assert_str_eq(actual, "test");
}
END_TEST

int main(void)
{
  Suite *trim = suite_create("Trim");
  TCase *trimming = tcase_create("Trimming");
  SRunner *sr = srunner_create(trim);

  suite_add_tcase(trim, trimming);

  tcase_add_test(trimming, shouldTrimLeadingWhitespace);
  tcase_add_test(trimming, shouldTrimTrailingWhitespace);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
