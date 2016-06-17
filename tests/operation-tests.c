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

START_TEST(shouldRecognizeSubtraction)
{
  const char* equation = "1 - 1";
  OPERATION op = getOperation(equation);

  ck_assert_int_eq(op, SUBTRACTION);
}
END_TEST

START_TEST(shouldRecognizeUnknownOperation)
{
  const char* equation = "1 * 1";
  OPERATION op = getOperation(equation);

  ck_assert_int_eq(op, UNKNOWN);
}
END_TEST

int main(void)
{
  Suite *operation = suite_create("Operation");
  TCase *operationParsing = tcase_create("Operation parsing");
  SRunner *sr = srunner_create(operation);

  suite_add_tcase(operation, operationParsing);

  tcase_add_test(operationParsing, shouldRecognizeAddition);
  tcase_add_test(operationParsing, shouldRecognizeSubtraction);
  tcase_add_test(operationParsing, shouldRecognizeUnknownOperation);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
