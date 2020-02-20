#include <cgreen/cgreen.h>

#include "fizzbuzz.h"

Describe(FizzBuzz);
BeforeEach(FizzBuzz) {}
AfterEach(FizzBuzz) {}

Ensure(FizzBuzz, test_fizzbuzz_WITH_0_SHOULD_return_null) {
  int* output = fizzbuzz(0);
  assert_that(output == NULL);
}

Ensure(FizzBuzz, test_fizzbuzz_to_2_SHOULD_return_all_numbers_except_0) {
  int* output = fizzbuzz(2);
  int expected[2] = {1,2};
  assert_that(output, is_equal_to_contents_of(expected, sizeof(expected)));
}

Ensure(FizzBuzz, test_third_entry_FROM_fizzbuzz_to_3_SHOULD_return_fizz) {
  int* output = fizzbuzz(3);
  assert_that(output[2], is_equal_to(FIZZ));
}

Ensure(FizzBuzz, test_fifth_entry_FROM_fizzbuzz_to_5_SHOULD_return_buzz) {
  int* output = fizzbuzz(5);
  assert_that(output[4], is_equal_to(BUZZ));
}

int main(int argc, char **argv) {
  TestSuite *suite = create_test_suite();
  add_test_with_context(suite, FizzBuzz, test_fizzbuzz_WITH_0_SHOULD_return_null);
  add_test_with_context(suite, FizzBuzz, test_fizzbuzz_to_2_SHOULD_return_all_numbers_except_0);
  add_test_with_context(suite, FizzBuzz, test_third_entry_FROM_fizzbuzz_to_3_SHOULD_return_fizz);
  add_test_with_context(suite, FizzBuzz, test_fifth_entry_FROM_fizzbuzz_to_5_SHOULD_return_buzz);
  return run_test_suite(suite, create_text_reporter());
}
