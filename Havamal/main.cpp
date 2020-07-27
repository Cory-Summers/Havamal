#include <iostream>
#include "AppWin.hpp"
#include "config-loader.hpp"
#include "gui-splashscreen.hpp"

int Counter()
{
  int i;
  for (i = 0; i < 1000; ++i)
  {
    std::cout << i << '\n';
  }
  return i;
}
int main(int argc, char* argv[])
{
  //Config::Loader::Get();
  //Havamal::AppWin* window = new Havamal::AppWin();
  Gui::SplashScreen splashscreen(&Counter);
  splashscreen.Run();
  return 0;
}