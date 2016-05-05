#include "src/fizzbuzz.h"
#include <gtest/gtest.h>

namespace {
using namespace xcode;
struct fizzbuzz_test : ::testing::Test {};

TEST_F(fizzbuzz_test, returnsNothingForZero) {
  auto ret = fizzbuzz(0);
  EXPECT_TRUE(ret.empty());
}
}
