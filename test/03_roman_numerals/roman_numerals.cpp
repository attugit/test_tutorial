#include "src/roman_numerals.h"
#include <gtest/gtest.h>

namespace {
using namespace xcode;
struct roman_test : ::testing::Test {};

TEST_F(roman_test, returnsIsForNumbersLessThenFour) {
  EXPECT_EQ(to_roman(1), "I");
  EXPECT_EQ(to_roman(2), "II");
  EXPECT_EQ(to_roman(3), "III");
}

TEST_F(roman_test, returnsVForFive) { EXPECT_EQ(to_roman(5), "V"); }
}
