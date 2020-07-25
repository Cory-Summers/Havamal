#include <iostream>
#include "AppWin.hpp"
#include "config-loader.hpp"
int main(int argc, char* argv[])
{
  Config::Loader::Get();
  //Havamal::AppWin* window = new Havamal::AppWin();
  return 0;
}