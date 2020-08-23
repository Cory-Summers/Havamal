#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include <SFML/System/Vector2.hpp>
#include <nlohmann/json.hpp>
namespace Havamal::Config {
  using JSON = nlohmann::json;
  template<typename T>
  sf::Vector2<T> ToVector(JSON::value_type const&);
  template<typename char_type>
  class Manager
  {
    using string_type   = std::basic_string<char_type>;
    using ofstream_type = std::basic_ofstream<char_type>;
    using ifstream_type = std::basic_ifstream<char_type>;
    using string_cref   = string_type const&;
  public:
    Manager();
    Manager(string_cref);
    void SetFileName(string_cref);
    string_cref GetFileName() const { return m_file_name; }
    void Read();
    void Write();
    JSON & operator[](string_cref key) { return m_json[key]; }
  protected:
    JSON         m_json;
    string_type  m_file_name;
  };
  template<typename char_type>
  inline Manager<char_type>::Manager()
    : m_json()
    , m_file_name()
  {
  }
  template<typename char_type>
  inline Manager<char_type>::Manager(string_cref name)
    : m_file_name(name)
    , m_json(JSON::parse(ifstream_type(name)))
  {
  }
  template<typename char_type>
  inline void Manager<char_type>::SetFileName(string_cref name)
  {
    m_file_name = name;
  }

  template<typename char_type>
  inline void Manager<char_type>::Read()
  {
    m_json = JSON::parse(ifstream_type(m_file_name));
  }

  template<typename char_type>
  inline void Manager<char_type>::Write()
  {
    ofstream_type of(m_file_name, std::ios_base::trunc);
    of << std::setw(4) << m_json << std::endl;
  }

  template<typename T>
  sf::Vector2<T> ToVector(JSON::value_type const& obj)
  {
    sf::Vector2<T> vec = {
      obj.at(0).get<T>(),
      obj.at(1).get<T>()
    };
    return vec;
  }
}