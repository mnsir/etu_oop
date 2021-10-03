#pragma once

#include <string>
#include <variant>

#include "number.h"

class TPolinom final {
private:
  constexpr static auto zero = Number{};

public:
  explicit TPolinom(Number a, Number b, Number c);

  std::variant<std::pair<Number, Number>, Number, std::string> Solve() const;
  Number Calc(Number x) const;
  explicit operator std::string() const;

private:
  Number A;
  Number B;
  Number C;
};
