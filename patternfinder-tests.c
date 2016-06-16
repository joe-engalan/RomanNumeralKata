/*
digitextractor-tests.c
*/

#include <check.h>
#include "romanconverter.h"

/* pattern TESTS */

START_TEST(shouldFindPattern)
{
  const char* patterns[] = { "aaa", "bbb", "acb" };
  const char* string = "acbaaabbb";
  int pattern = findPatternInString(string, patterns);

  ck_assert_int_ne(pattern, -1);
}
END_TEST

int main(void)
{
  Suite *pattern = suite_create("Pattern");
  TCase *patternFinding = tcase_create("PatternFinding");
  SRunner *sr = srunner_create(pattern);

  suite_add_tcase(pattern, patternFinding);

  tcase_add_test(patternFinding, shouldFindPattern);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
