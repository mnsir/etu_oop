#include <iostream>

#include "application.h"
#include "polinom.h"

int main() {
  std::cout << R"(commands:
set double double double
solve
calc double
print
exit)" << std::endl;

  auto &app = TApplication::GetInstance();
  auto polinom = TPolinom({}, {}, {});

  while (app) {
    std::cin >> app;
    app.ExecuteWith(polinom);
    std::cout << app << std::endl;
  }

  std::cout << "done" << std::endl;

  return 0;
}
