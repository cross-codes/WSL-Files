#include <iostream>
#include <format>

int main()
{
  std::cout << "Enter three numbers: ";

  int x, y, z;
  std::cin >> x >> y >> z;

  std::cout << (x = 5) << "\n";

  std::cout << std::format("You entered: {}, {}, and {}\n", x, y, z);
}
