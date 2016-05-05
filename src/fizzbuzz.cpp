#include "src/fizzbuzz.h"

std::vector<std::string> xcode::fizzbuzz(std::size_t n) {
  std::vector<std::string> ret{};
  ret.reserve(n);
  auto idx = 0u;
  while (++idx, n-- > 0) {
    if (idx % 15u == 0)
      ret.push_back("fizzbuzz");
    else if (idx % 3u == 0u)
      ret.push_back("fizz");
    else if (idx % 5u == 0u)
      ret.push_back("buzz");
    else
      ret.push_back(std::to_string(idx));
  }
  return ret;
}
