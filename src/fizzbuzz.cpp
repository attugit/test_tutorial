#include "src/fizzbuzz.h"

std::vector<std::string> xcode::fizzbuzz(std::size_t n) {
  std::vector<std::string> ret{};
  auto idx = 0u;
  while (++idx, n-- > 0) ret.push_back(std::to_string(idx));
  return ret;
}
