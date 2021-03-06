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

TEST_F(roman_test, useXCToRepresentNinetyAndCToRepresentOneHundred) {
  EXPECT_EQ(to_roman(89), "LXXXIX");
  EXPECT_EQ(to_roman(90), "XC");
  EXPECT_EQ(to_roman(99), "XCIX");
  EXPECT_EQ(to_roman(100), "C");
  EXPECT_EQ(to_roman(101), "CI");
  EXPECT_EQ(to_roman(139), "CXXXIX");
  EXPECT_EQ(to_roman(149), "CXLIX");
}

TEST_F(roman_test, useCDToRepresentFourHundredAndDToRepresentFiveHundred) {
  EXPECT_EQ(to_roman(399), "CCCXCIX");
  EXPECT_EQ(to_roman(400), "CD");
  EXPECT_EQ(to_roman(499), "CDXCIX");
  EXPECT_EQ(to_roman(500), "D");
  EXPECT_EQ(to_roman(549), "DXLIX");
  EXPECT_EQ(to_roman(588), "DLXXXVIII");
}

TEST_F(roman_test, useCMToRepresentNineHoundredMToRepresentThousand) {
  EXPECT_EQ(to_roman(899), "DCCCXCIX");
  EXPECT_EQ(to_roman(900), "CM");
  EXPECT_EQ(to_roman(901), "CMI");
  EXPECT_EQ(to_roman(999), "CMXCIX");
  EXPECT_EQ(to_roman(1000), "M");
  EXPECT_EQ(to_roman(1001), "MI");
  EXPECT_EQ(to_roman(2016), "MMXVI");
}
}
