#include "src/roman_numerals.h"
#include <gtest/gtest.h>

namespace {
using namespace xcode;
struct roman_test : ::testing::Test {};

TEST_F(roman_test, returnsIforOne) { EXPECT_EQ(to_roman(1), "I"); }
}
