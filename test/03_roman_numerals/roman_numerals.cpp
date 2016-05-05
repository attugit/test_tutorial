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

TEST_F(roman_test, useIVToRepresentFourAndVToRepresentFive) {
  EXPECT_EQ(to_roman(4), "IV");
  EXPECT_EQ(to_roman(5), "V");
  EXPECT_EQ(to_roman(6), "VI");
  EXPECT_EQ(to_roman(7), "VII");
  EXPECT_EQ(to_roman(8), "VIII");
}

TEST_F(roman_test, useIXToRepresentNineAndXToRepresentTen) {
  EXPECT_EQ(to_roman(9), "IX");
  EXPECT_EQ(to_roman(10), "X");
  EXPECT_EQ(to_roman(11), "XI");
  EXPECT_EQ(to_roman(12), "XII");
  EXPECT_EQ(to_roman(13), "XIII");
  EXPECT_EQ(to_roman(14), "XIV");
  EXPECT_EQ(to_roman(15), "XV");
}

TEST_F(roman_test, useXLToRepresentFourtyAndLToRepresentFifty) {
  EXPECT_EQ(to_roman(39), "XXXIX");
  EXPECT_EQ(to_roman(40), "XL");
  EXPECT_EQ(to_roman(41), "XLI");
  EXPECT_EQ(to_roman(44), "XLIV");
  EXPECT_EQ(to_roman(49), "XLIX");
  EXPECT_EQ(to_roman(50), "L");
  EXPECT_EQ(to_roman(54), "LIV");
}
}
