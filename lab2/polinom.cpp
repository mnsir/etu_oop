#include "polinom.h"

#include <cmath>
#include <iomanip>
#include <sstream>

TPolinom::TPolinom(Number a, Number b, Number c) : A{a}, B{b}, C{c} {}

std::variant<std::pair<Number, Number>, Number, std::string>
TPolinom::Solve() const {
  if (A == zero) {
    if (B == zero) {
      return "no roots";
    }
    return Number(-C / B); // one root
  } else {
    if (auto D = B * B - Number(4) * A * C; D == zero) {
      return Number(-B / (Number(2) * A)); // one root
    } else {
      auto r1 = Number((-B + std::sqrt(D)) / (Number(2) * A));
      auto r2 = Number((-B - std::sqrt(D)) / (Number(2) * A));
      return std::make_pair(r1, r2); // two roots
    }
  }
  return "";
}

Number TPolinom::Calc(Number x) const { return Number(A * x * x + B * x + C); }

TPolinom::operator std::string() const {
  std::ostringstream ss;
  ss << std::showpos << A << "*x^2 + " << B << "*x + " << C;
  return ss.str();
}
