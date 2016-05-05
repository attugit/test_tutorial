#include "src/fizzbuzz.h"
#include <gtest/gtest.h>

namespace {
using namespace xcode;
struct fizzbuzz_test : ::testing::Test {};

TEST_F(fizzbuzz_test, returnsNothingForZero) {
  auto ret = fizzbuzz(0);
  EXPECT_TRUE(ret.empty());
}

TEST_F(fizzbuzz_test, returnsStringRepresentationOfNumbersUpToThree) {
  {
    auto ret = fizzbuzz(1);
    ASSERT_EQ(ret.size(), 1u);
    EXPECT_EQ(ret[0], "1");
  }
  {
    auto ret = fizzbuzz(2);
    ASSERT_EQ(ret.size(), 2u);
    EXPECT_EQ(ret[0], "1");
    EXPECT_EQ(ret[1], "2");
  }
}

TEST_F(fizzbuzz_test, returnsFizzWhenNumberDivisibleByThree) {
  {
    auto ret = fizzbuzz(3);
    ASSERT_EQ(ret.size(), 3u);
    EXPECT_EQ(ret[0], "1");
    EXPECT_EQ(ret[1], "2");
    EXPECT_EQ(ret[2], "fizz");
  }
  {
    auto ret = fizzbuzz(4);
    ASSERT_EQ(ret.size(), 4u);
    EXPECT_EQ(ret[0], "1");
    EXPECT_EQ(ret[1], "2");
    EXPECT_EQ(ret[2], "fizz");
    EXPECT_EQ(ret[3], "4");
  }
}

TEST_F(fizzbuzz_test, returnsBuzzWhenNumberDivisibleByFive) {
  {
    auto ret = fizzbuzz(5);
    ASSERT_EQ(ret.size(), 5u);
    EXPECT_EQ(ret[0], "1");
    EXPECT_EQ(ret[1], "2");
    EXPECT_EQ(ret[2], "fizz");
    EXPECT_EQ(ret[3], "4");
    EXPECT_EQ(ret[4], "buzz");
  }
  {
    auto ret = fizzbuzz(6);
    ASSERT_EQ(ret.size(), 6u);
    EXPECT_EQ(ret[0], "1");
    EXPECT_EQ(ret[1], "2");
    EXPECT_EQ(ret[2], "fizz");
    EXPECT_EQ(ret[3], "4");
    EXPECT_EQ(ret[4], "buzz");
    EXPECT_EQ(ret[5], "fizz");
  }
}

TEST_F(fizzbuzz_test, returnsFizzBuzzWhenNumberDivisibleByFifteen) {
  auto ret = fizzbuzz(16);
  ASSERT_EQ(ret.size(), 16u);
  EXPECT_EQ(ret[0], "1");
  EXPECT_EQ(ret[1], "2");
  EXPECT_EQ(ret[2], "fizz");
  EXPECT_EQ(ret[3], "4");
  EXPECT_EQ(ret[4], "buzz");
  EXPECT_EQ(ret[5], "fizz");
  EXPECT_EQ(ret[6], "7");
  EXPECT_EQ(ret[7], "8");
  EXPECT_EQ(ret[8], "fizz");
  EXPECT_EQ(ret[9], "buzz");
  EXPECT_EQ(ret[10], "11");
  EXPECT_EQ(ret[11], "fizz");
  EXPECT_EQ(ret[12], "13");
  EXPECT_EQ(ret[13], "14");
  EXPECT_EQ(ret[14], "fizzbuzz");
  EXPECT_EQ(ret[15], "16");
}
}
