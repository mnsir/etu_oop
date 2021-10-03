#pragma once

#include <iosfwd>
#include <string>
#include <vector>

#include "polinom.h"

class TApplication final {
private:
  TApplication() = default;

public:
  TApplication(const TApplication &) = delete;
  TApplication(TApplication &&) = delete;
  TApplication &operator=(const TApplication &) = delete;
  TApplication &operator=(TApplication &&) = delete;

  static TApplication &GetInstance();

  operator bool() const { return active; }

  void ExecuteWith(TPolinom &);

  friend std::istream &operator>>(std::istream &, TApplication &);
  friend std::ostream &operator<<(std::ostream &, const TApplication &);

private:
  bool active = true;
  std::string action;
  std::vector<std::string> args;
  std::string log;
};

std::istream &operator>>(std::istream &, TApplication &);
std::ostream &operator<<(std::ostream &, const TApplication &);
