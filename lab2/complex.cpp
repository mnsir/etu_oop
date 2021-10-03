#include "complex.h"

#include <sstream>

namespace std {

string to_string(const TComplex &c) {
  std::ostringstream os;
  os << c;
  return os.str();
}

} // namespace std
