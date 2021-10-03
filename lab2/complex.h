#pragma once

#include <complex>

class TComplex final : public std::complex<double> {
public:
  using std::complex<double>::complex;
};

namespace std {
string to_string(const TComplex &c);
} // namespace std
