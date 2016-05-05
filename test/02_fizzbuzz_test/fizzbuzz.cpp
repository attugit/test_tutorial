#include "src/fizzbuzz.h"
#include <gtest/gtest.h>

namespace {
using namespace xcode;
struct fizzbuzz_test : ::testing::Test {
  std::vector<std::string> ret;

  enum { max_size = 101 };

  void SetUp() override {
    ret = fizzbuzz(max_size);
    ASSERT_EQ(ret.size(), max_size);
  }
};

TEST_F(fizzbuzz_test, returnsSequenceOfGivenSize) {
  for (auto idx = 0u; idx < max_size; ++idx) ASSERT_EQ(fizzbuzz(idx).size(), idx);
}

TEST_F(fizzbuzz_test, returnsStringRepresentationOfNumbersUpToThree) {
  for (auto idx = 0u; idx < max_size; ++idx) {
    auto number = idx + 1;
    if (number % 3 != 0 && number % 5 != 0) EXPECT_EQ(ret[idx], std::to_string(number));
  }
}

TEST_F(fizzbuzz_test, returnsFizzWhenNumberDivisibleByThree) {
  for (auto idx = 0u; idx < max_size; ++idx) {
    auto number = idx + 1;
    if (number % 3 == 0 && number % 5 != 0) EXPECT_EQ(ret[idx], "fizz");
  }
}

TEST_F(fizzbuzz_test, returnsBuzzWhenNumberDivisibleByFive) {
  for (auto idx = 0u; idx < max_size; ++idx) {
    auto number = idx + 1;
    if (number % 3 != 0 && number % 5 == 0) EXPECT_EQ(ret[idx], "buzz");
  }
}

TEST_F(fizzbuzz_test, returnsFizzBuzzWhenNumberDivisibleByFifteen) {
  for (auto idx = 0u; idx < max_size; ++idx) {
    auto number = idx + 1;
    if (number % 15 == 0) EXPECT_EQ(ret[idx], "fizzbuzz");
  }
}
}
