#pragma once
#include <map>
#include <string>
#include <SFML/Graphics/Font.hpp>
namespace Havamal {
  class FontLibrary
  {
  public:
    static FontLibrary& Get();
    sf::Font& operator[](std::string const&);
    sf::Font& LoadFullPath(std::string const&, std::string const&);
    void Unload(std::string const& key) { m_map.erase(key); }
  private:
    static FontLibrary Initialize();
    FontLibrary() {}
    std::string GetWindowsFontPath() const;
    std::string GetUserFontPath() const;
    std::string FindFile(std::string const&) const;
    void LoadLocalFolder();
    std::map<std::string, sf::Font> m_map;
    std::string os_font_dir;
    std::string usr_font_dir;
    static const std::string local_folder;
  };
}