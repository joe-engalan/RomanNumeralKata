/*
calculator-tests.c
*/

#include <check.h>
#include "calculator.h"

/* CALCULATOR TESTS */

START_TEST(shouldFailIfInvalidOperationType)
{
  const char* equation = "MM/MM";
  char result[80];

  STATUS_TYPE status = calculate(result, equation);

  ck_assert_int_eq(status, ERROR_OPERATION);
}
END_TEST

START_TEST(shouldFailIfOperandInsufficientOperands)
{
  const char* equation = "+MM";
  char result[80];

  STATUS_TYPE status = calculate(result, equation);

  ck_assert_int_eq(status, ERROR_INSUFFICIENT_OPPERANDS);
}
END_TEST

START_TEST(shouldFailIfResultIsLessThan0)
{
  const char* equation = "M-MM";
  char result[80];

  STATUS_TYPE status = calculate(result, equation);

  ck_assert_int_eq(status, ERROR_UNDERFLOW);
}
END_TEST

START_TEST(shouldFailIfResultIsMoreThan3999)
{
  const char* equation = "MM+MM";
  char result[80];

  STATUS_TYPE status = calculate(result, equation);

  ck_assert_int_eq(status, ERROR_OVERFLOW);
}
END_TEST

START_TEST(shouldCalculateEquation)
{
  const char* equation = "MM+M";
  char result[80];

  STATUS_TYPE status = calculate(result, equation);

  ck_assert_int_eq(status, STATUS_OK);
  ck_assert_str_eq(result, "MMM");
}
END_TEST

START_TEST(shouldRecognizeInvalidOperand1)
{
  const char* equation = "abc+M";
  char result[80];

  STATUS_TYPE status = calculate(result, equation);

  ck_assert_int_eq(status, ERROR_INVALID_OPERAND);
}
END_TEST

START_TEST(shouldRecognizeInvalidOperand2)
{
  const char* equation = "M-abc";
  char result[80];

  STATUS_TYPE status = calculate(result, equation);

  ck_assert_int_eq(status, ERROR_INVALID_OPERAND);
}
END_TEST

int main(void)
{
  Suite *suite = suite_create("Calculator");
  TCase *tcase = tcase_create("CalculatorTests");
  SRunner *sr = srunner_create(suite);

  suite_add_tcase(suite, tcase);

  tcase_add_test(tcase, shouldFailIfInvalidOperationType);
  tcase_add_test(tcase, shouldFailIfOperandInsufficientOperands);
  tcase_add_test(tcase, shouldFailIfResultIsLessThan0);
  tcase_add_test(tcase, shouldFailIfResultIsMoreThan3999);
  tcase_add_test(tcase, shouldCalculateEquation);
  tcase_add_test(tcase, shouldRecognizeInvalidOperand1);
  tcase_add_test(tcase, shouldRecognizeInvalidOperand2);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
