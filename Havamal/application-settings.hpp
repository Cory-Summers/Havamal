#pragma once
#include <fstream>
#include <string>
namespace Havamal {
  using generic_char     = char;
  using generic_string   = std::basic_string<generic_char>;
  using generic_ofstream = std::basic_ofstream<generic_char>;
  using generic_ifstream = std::basic_ifstream<generic_char>;
}