/*
operation-tests.c
*/

#include <check.h>
#include "operation.h"

/* operation TESTS */

START_TEST(shouldRecognizeAddition)
{
  const char* equation = "1 + 1";
  OPERATION op = getOperation(equation);

  ck_assert_int_eq(op, ADDITION);
}
END_TEST

int main(void)
{
  Suite *operation = suite_create("Operation");
  TCase *operationParsing = tcase_create("Operation parsing");
  SRunner *sr = srunner_create(operation);

  suite_add_tcase(operation, operationParsing);

  tcase_add_test(operationParsing, shouldRecognizeAddition);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
