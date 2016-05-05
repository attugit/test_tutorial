#include <gtest/gtest.h>

namespace {
struct no_test : ::testing::Test {};

TEST_F(no_test, nothing) {}
}
