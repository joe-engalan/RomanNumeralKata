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

START_TEST(shouldGetOperands)
{
  char equation[80] = "1 + 2";
  char* operands[2];

  int numOperands = getOperands(operands, equation);

  ck_assert_int_eq(numOperands, 2);
  ck_assert_str_eq(operands[0], "1");
  ck_assert_str_eq(operands[1], "2");
}
END_TEST

START_TEST(shouldFailIfOperand1IsMissing)
{
  char equation[80] = "+ 2";
  char* operands[2];

  int numOperands = getOperands(operands, equation);

  ck_assert_int_eq(numOperands, 1);
}
END_TEST

START_TEST(shouldFailIfOperand2IsMissing)
{
  char equation[80] = "1 +";
  char* operands[2];

  int numOperands = getOperands(operands, equation);

  ck_assert_int_eq(numOperands, 1);
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
  tcase_add_test(operationParsing, shouldGetOperands);
  tcase_add_test(operationParsing, shouldFailIfOperand1IsMissing);
  tcase_add_test(operationParsing, shouldFailIfOperand2IsMissing);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
