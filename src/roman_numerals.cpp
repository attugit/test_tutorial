#include "src/roman_numerals.h"
#include <boost/algorithm/string/replace.hpp>

std::string xcode::to_roman(std::size_t n) {
  auto ret = std::string(n, 'I');
  boost::replace_all(ret, "IIIII", "V");
  return ret;
}
