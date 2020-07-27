#include "gui-splashscreen.hpp"
const sf::Color k_bg_transparent = sf::Color(0x0);


Gui::SplashScreen::SplashScreen(callback_type const& callback)
  : m_window(sf::VideoMode(1280, 720), "", sf::Style::None)
  , m_callback(callback)
  , m_callback_thread()
  , m_event()
  , m_rect_test({ 400, 720 })
{
  m_rect_test.setFillColor({ 8, 50, 83 });
  
}

void Gui::SplashScreen::Initialize()
{
}

int Gui::SplashScreen::Run()
{
  auto start = std::chrono::steady_clock::now();
  auto end = std::chrono::steady_clock::now();
  bool joined = false;
  m_callback_thread = std::thread(m_callback);
  while (((std::chrono::duration_cast<std::chrono::seconds>(end - start).count() <= 15ull) || !joined) && m_window.isOpen())
  {
    PollEvent();
    m_window.clear(k_bg_transparent);
    m_window.draw(m_rect_test);
    m_window.display();
    if (m_callback_thread.joinable())
    {
      m_callback_thread.join();
      joined = true;
    }
    end = std::chrono::steady_clock::now();
  }
  return 1;
}

void Gui::SplashScreen::PollEvent()
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
