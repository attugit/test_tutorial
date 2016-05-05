#include "src/roman_numerals.h"
#include <boost/algorithm/string/replace.hpp>

std::string xcode::to_roman(std::size_t n) {
  auto ret = std::string(n, 'I');
  boost::replace_all(ret, "IIIII", "V");
  boost::replace_all(ret, "IIII", "IV");
  boost::replace_all(ret, "VV", "X");
  boost::replace_all(ret, "VIV", "IX");
  boost::replace_all(ret, "XXXXX", "L");
  boost::replace_all(ret, "XXXX", "XL");
  boost::replace_all(ret, "LL", "C");
  boost::replace_all(ret, "LXL", "XC");
  boost::replace_all(ret, "CCCCC", "D");
  boost::replace_all(ret, "CCCC", "CD");
  boost::replace_all(ret, "DD", "M");
  boost::replace_all(ret, "DCD", "CM");
  return ret;
}
