#include <iostream>
#include "AppWin.hpp"
#include "gui-splashscreen.hpp"
#include "Bootstrapper.h"
int main(int argc, char* argv[])
{
  std::unique_ptr<Havamal::SplashScreen<std::shared_ptr<Havamal::AppWin>>> splashscreen(std::make_unique<Havamal::SplashScreen<std::shared_ptr<Havamal::AppWin>>>(&Havamal::Bootstrapper::Load));
  auto window = splashscreen->Execute();
  window->Initialize();
  return window->Execute();
}