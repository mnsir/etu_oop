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
    return -C / B; // one root
  } else {
    if (auto D = B * B - 4 * A * C; D == zero) {
      return -B / (2 * A); // one root
    } else if (D > zero) {
      auto r1 = (-B + std::sqrt(D)) / (2 * A);
      auto r2 = (-B - std::sqrt(D)) / (2 * A);
      return std::make_pair(r1, r2); // two roots
    } else /*if (D < zero)*/ {
      return "no real roots";
    }
  }
  return "";
}

Number TPolinom::Calc(Number x) const { return A * x * x + B * x + C; }

TPolinom::operator std::string() const {
  std::ostringstream ss;
  ss << std::showpos;
  if (A != zero)
    ss << A << "*x^2";
  if (B != zero)
    ss << B << "*x";
  if (C != zero)
    ss << C;
  if (auto str = ss.str(); !str.empty())
    return str.substr(1);
  return "empty";
}
