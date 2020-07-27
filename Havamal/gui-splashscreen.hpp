#pragma once
#include <chrono>
#include <functional>
#include <thread>
#include <future>
#include <SFML/Graphics.hpp>
namespace Gui {
  class SplashScreen
  {
    using callback_type = std::function<int()>;
  public:
    SplashScreen(callback_type const &);
    void Initialize();
    int  Run();
  private:
    void PollEvent();
    std::thread m_callback_thread;
    callback_type m_callback;
    sf::RenderWindow m_window;
    sf::RectangleShape m_rect_test;
    sf::Event m_event;

  };
}