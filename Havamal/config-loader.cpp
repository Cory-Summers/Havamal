#include "config-loader.hpp"
#include <array>
#include <regex>
/*
Config::Loader& Config::Loader::Get()
{
  static Loader m_this = Initialize();
  return m_this;
}

Config::Loader Config::Loader::Initialize(std::string path)
{
  Loader temp;
  temp.m_cfg_file = std::fstream(path);
  temp.ReadFile();
  return temp;
}

void Config::Loader::ReadFile()
{
  const std::regex lhs_rgx("[:alpha]");
  const std::regex rhs_int_rgx("");
  const std::regex lhs_rgx("[:alpha]");
  const std::regex lhs_rgx("[:alpha]");
  std::array<char, 256> c_arr;
  std::string str;
  while (!m_cfg_file.eof())
  {
    std::getline(m_cfg_file, str);
    std::cout << str << '\n';
  }
}
*/