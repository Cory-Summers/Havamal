#pragma once
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include <SFML/Graphics/Color.hpp>
#include "application-settings.hpp"
namespace Havamal::Gui {
  template<typename char_type = generic_char>
  class ColorScheme
  {
    using string_type  = std::basic_string<char_type>;
    using hash_table   = std::unordered_map<string_type, sf::Color>;
    using stringstream = std::basic_stringstream<char_type>;
    using ofstream_type = std::basic_ofstream<char_type>;
    using ifstream_type = std::basic_ifstream<char_type>;
  public:
    ColorScheme() {}
    ColorScheme(string_type);
    void Load();
    void Load(string_type const);
    void Save();
    sf::Color & operator[](string_type const&);
  private:
    string_type m_file_name;
    hash_table m_table;
  };
  template<typename char_type>
  inline ColorScheme<char_type>::ColorScheme(string_type name)
    : m_file_name(name)
    , m_table()
  {
    Load();
  }
  template<typename char_type>
  inline void ColorScheme<char_type>::Load()
  {
    nlohmann::json parser = nlohmann::json::parse(ifstream_type(m_file_name));
    sf::Color value;
    std::uint32_t hex;
    for (auto color = parser.begin(); color != parser.end(); ++color)
    {
      hex = std::stoul(color.value().get<string_type>(), nullptr, 16);
      value = sf::Color(hex);
      m_table[color.key()] = value;
    }
  }
  template<typename char_type>
  inline void ColorScheme<char_type>::Load(string_type const name)
  {
    m_file_name = name;
    Load();
  }
  template<typename char_type>
  inline void ColorScheme<char_type>::Save()
  {
  }
  template<typename char_type>
  inline sf::Color& ColorScheme<char_type>::operator[](string_type const& name)
  {
    return m_table[name];
  }
}

