#include <gtest/gtest.h>
#include "src/file.h"

namespace {
using namespace xcode;
struct generated_test : ::testing::Test {
  using sut_t = Aggregate::table;
  sut_t sut;
  void SetUp() override {
    sut.reserve(5);
    sut.emplace_back();
    sut.emplace_back();
    sut.emplace_back();
  }
};

TEST_F(generated_test, canCallGeneratedWrapper) {
  ASSERT_EQ(sut.size(), 3u);
  EXPECT_FALSE(sut[0].third());
  sut[0].set_third(4.0);
  ASSERT_TRUE(sut[0].third());
  EXPECT_EQ(*(sut[0].third()), 4.0);
}
}
