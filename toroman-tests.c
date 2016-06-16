/*
toroman-tests.c
*/

#include <check.h>
#include "toroman.h"

START_TEST(shouldConvert5)
{
  char numeral[20];
  toRoman(numeral, 5);

  ck_assert_str_eq(numeral, "V");
}
END_TEST

int main(void)
{
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, shouldConvert5);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
