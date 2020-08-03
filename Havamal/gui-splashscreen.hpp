#pragma once
#include <chrono>
#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <SFML/Graphics.hpp>
#include "FontLibarary.h"
#include "m-utility.hpp"
#include <dwmapi.h>
namespace Havamal {
  template<typename return_type>
  class SplashScreen
  {
    using atom_float = std::atomic<float>;
    using atom_bool = std::atomic<bool>;
    using callback_type = std::function<return_type(atom_float &, atom_bool &)>;
  public:
    SplashScreen(callback_type const &);
    void Initialize();
    return_type Run();
    ~SplashScreen();
  private:
    void PollEvent();
    void LoadBackground();
    void CreateText();
    void UpdateLoadingBar(std::chrono::milliseconds const &);
    callback_type m_callback;
    sf::RenderWindow m_window;
    sf::Event m_event;

    sf::RectangleShape m_loading_bar;

    sf::RectangleShape m_bg;
    sf::Texture m_bg_texture;

    sf::Text m_title;
    sf::Text runes;
    atom_float m_progress;
    atom_bool  m_done;
    static const sf::Color k_bg_color_l;
    static const sf::Color k_bg_color_h;
  };
}
template<typename T>
const sf::Color Havamal::SplashScreen<T>::k_bg_color_l = sf::Color(11, 28, 36);
template<typename T>
const sf::Color Havamal::SplashScreen<T>::k_bg_color_h = sf::Color(20, 52, 67);


template<typename return_type>
Havamal::SplashScreen<return_type>::SplashScreen(callback_type const& callback)
  : m_window(sf::VideoMode(1600, 1000), "", sf::Style::None)
  , m_callback(callback)
  , m_event()
  , m_loading_bar()
  , m_progress(0.01f)
  , m_done(false)
  , m_title("Havamal Editor", FontLibrary::Get()["Raleway-Regular.ttf"], 100)
  , runes(
    L"\x16BC\x16C5\x16A2\x16C5\x16C9\x16AC\x16DA", //Havaml in Runes
    FontLibrary::Get()["junicode.ttf"], 
    100)
{
  Initialize();
}
template<typename return_type>
void Havamal::SplashScreen<return_type>::Initialize()
{
  m_window.setFramerateLimit(30);
  m_loading_bar.setFillColor({ 0xf0,0xf0,0xf0 });
  m_loading_bar.setSize({ m_window.getSize().x * m_progress.load(), 25 });
  m_loading_bar.setPosition({ 0.f, m_window.getSize().y - 25.f });
  CreateText();
  LoadBackground();
}

template<typename return_type>
void Havamal::SplashScreen<return_type>::PollEvent()
{
  while (m_window.pollEvent(m_event))
  {
    if (m_event.type == sf::Event::Closed)
    {
      m_window.close();
    }
    else if (m_event.type == sf::Event::KeyReleased)
    {
      if (m_event.key.code == sf::Keyboard::C && m_event.key.alt)
        m_window.close();
    }
  }
}
template<typename return_type>
inline void Havamal::SplashScreen<return_type>::LoadBackground()
{
  /*m_bg_texture.loadFromFile("bg.png");
  m_bg.setTexture(&m_bg_texture);
  m_bg.setSize(sf::Vector2f(m_window.getSize()) - sf::Vector2f({50.f, 50.f}));
  m_bg.setPosition({ 25.f, 25.f });*/

}
template<typename return_type>
inline void Havamal::SplashScreen<return_type>::CreateText()
{
  const sf::Color text_color = sf::Color(96, 163, 169);//sf::Color(0x519794ff);
  m_title.setPosition(Util::CenterObject(m_title.getLocalBounds(), sf::Vector2f(m_window.getSize())).x, 200);
  runes.setPosition(Util::CenterObject(runes.getLocalBounds(), sf::Vector2f(m_window.getSize())));
  runes.setFillColor(text_color);
  m_title.setFillColor(text_color);
}
template<typename return_type>
inline void Havamal::SplashScreen<return_type>::UpdateLoadingBar(std::chrono::milliseconds const & delta)
{
  m_loading_bar.setSize(
    { m_window.getSize().x * ( delta.count() / static_cast<float>(5e3)) * 1.f,
    m_loading_bar.getSize().y 
    }
  );
}
template<typename return_type>
return_type Havamal::SplashScreen<return_type>::Run()
{
  auto start = std::chrono::steady_clock::now();
  auto end = std::chrono::steady_clock::now();
  bool joined = false;
  std::chrono::milliseconds delta_t;
  std::future<return_type> result = std::async(
    std::launch::async, 
    m_callback, 
    std::ref(m_progress),
    std::ref(m_done)
  );

  while ((/*(delta_t.count() <= (std::int64_t)5e3) ||*/ !joined) && m_window.isOpen())
  {
    PollEvent();
    m_window.clear(sf::Color(16, 20, 20));
    m_window.draw(m_title);
    m_window.draw(runes);
    m_window.draw(m_loading_bar);
    m_window.display();
    UpdateLoadingBar(delta_t);
    if (m_done.load())
      joined = true;
    end = std::chrono::steady_clock::now();
    delta_t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  }
  m_window.close();
  return result.get();
}

template<typename return_type>
inline Havamal::SplashScreen<return_type>::~SplashScreen()
{
  FontLibrary::Get().Unload("seguihis.ttf");
}
