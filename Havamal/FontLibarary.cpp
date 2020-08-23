#include "FontLibarary.h"
#ifdef _WIN32
#include <Windows.h>
#endif
#include <array>
#include <iostream>
#include <filesystem> 
const std::string Havamal::FontLibrary::local_folder = std::string("./fonts/");
Havamal::FontLibrary& Havamal::FontLibrary::Get()
{
  static FontLibrary m_this = Initialize();
  //test;
  return m_this;
}


sf::Font& Havamal::FontLibrary::operator[](std::string const& font_path)
{
  auto iter = m_map.find(font_path);
  if (iter == m_map.end())
  {
    sf::Font temp;
    std::string full_path = FindFile(font_path);
    if(full_path.empty())
    {
      return m_map["arial.ttf"];
    }
    temp.loadFromFile(full_path);
    m_map[font_path] = temp;
  }
  return m_map[font_path];
}

sf::Font& Havamal::FontLibrary::LoadFullPath(std::string const & key, std::string const& path)
{
  sf::Font temp;
  temp.loadFromFile(path);
  m_map[key] = temp;
  return m_map[key];
}

Havamal::FontLibrary Havamal::FontLibrary::Initialize()
{
  FontLibrary lib;
  lib.os_font_dir  = lib.GetWindowsFontPath();
  lib.usr_font_dir = lib.GetUserFontPath();
  lib["arial.ttf"];
  lib.LoadLocalFolder();
  return lib;
}

std::string Havamal::FontLibrary::GetWindowsFontPath() const
{
  std::array<char, 256> str_arr;
  UINT size;
  size = GetWindowsDirectoryA(str_arr.data(), str_arr.max_size());
  if (size == 0)
    throw;
  return std::string(str_arr.data()) + std::string("\\fonts\\");
}

std::string Havamal::FontLibrary::GetUserFontPath() const
{
  return std::string();
}

std::string Havamal::FontLibrary::FindFile(std::string const& path) const
{
  if(std::filesystem::exists(local_folder  + path))
    return (local_folder + path);
  if (std::filesystem::exists(os_font_dir  + path))
    return (os_font_dir + path);
  if (std::filesystem::exists(usr_font_dir + path))
    return (usr_font_dir + path);
  return std::string();
}

void Havamal::FontLibrary::LoadLocalFolder()
{
  sf::Font temp;
  std::cout << "Loading >\n";
  for (const auto& entry : std::filesystem::directory_iterator(local_folder))
  {
    if (entry.is_regular_file())
    {
      std::string ext = entry.path().extension().string();
      if (ext == ".ttf" || ext == ".otf")
      {
        std::cout <<'\t'<< entry.path().filename() << '\n';
        temp.loadFromFile(entry.path().string());
        m_map[entry.path().filename().string()] = temp;
      }
    }
  }
}
