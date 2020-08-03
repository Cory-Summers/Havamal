#include <iostream>
#include "AppWin.hpp"
#include "config-loader.hpp"
#include "gui-splashscreen.hpp"
#include "Bootstrapper.h"
int Counter()
{

}
int main(int argc, char* argv[])
{
  //Config::Loader::Get();
  //Havamal::AppWin* window = new Havamal::AppWin();
  int i;
  Havamal::SplashScreen<std::shared_ptr<Havamal::AppWin>> * splashscreen = new Havamal::SplashScreen<std::shared_ptr<Havamal::AppWin>>(&Havamal::Bootstrapper::Load);
  auto window = splashscreen->Run();
  delete splashscreen;
  window->Initialize();
  window->Run();
  return 0;
}