#include <nlohmann/json.hpp>
#include <iostream>
int main(int argc, char **argv)
{
  nlohmann::json j;
  j.push_back(1);
  j.push_back("foo");
  j.push_back(1);
  j.push_back(true);
  for (auto &i : j)
    std::cout << i << std::endl;

  return 0;
}