#include <sstream>
#include <string>

#include "application.h"

TApplication &TApplication::GetInstance() {
  static TApplication app;
  return app;
}

void TApplication::ExecuteWith(TPolinom &p) {
  auto conv = [](std::string &str) {
    std::istringstream ss(std::move(str));
    Number x;
    ss >> x;
    return x;
  };
  log.clear();
  if (!action.empty()) {
    if (action == "exit" && args.empty())
      active = false;
    else if (action == "set" && args.size() == 3U) {
      p = TPolinom(conv(args[0]), conv(args[1]), conv(args[2]));
    } else if (action == "solve" && args.empty()) {
      std::visit(
          [this](auto &&arg) {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::string>)
              log = "result: " + arg;
            else if constexpr (std::is_same_v<T, Number>)
              log = "result: " + std::to_string(arg);
            else if constexpr (std::is_same_v<T, std::pair<Number, Number>>)
              log = "result: " + std::to_string(arg.first) + ' ' +
                    std::to_string(arg.second);
            else
              static_assert(!sizeof(T), "no match visitor type");
          },
          p.Solve());
    } else if (action == "calc" && args.size() == 1U) {
      log = "result: " + std::to_string(p.Calc(conv(args.front())));
    } else if (action == "print" && args.empty()) {
      log = static_cast<std::string>(p);
    }
  }
}

std::istream &operator>>(std::istream &is, TApplication &app) {
  std::string str;
  if (std::getline(is, str)) {
    std::istringstream ss(std::move(str));

    app.action.clear();
    app.args.clear();

    if (ss >> str)
      app.action = std::move(str);

    while (ss >> str)
      app.args.emplace_back(std::move(str));
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, const TApplication &app) {
  if (!app.log.empty()) {
    os << app.log;
  }
  return os;
}
