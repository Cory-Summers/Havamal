#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
namespace Havamal {
  class IChildWindow
  {
  public:
    virtual void Initialize() = 0;
    virtual std::size_t Update() = 0;
    virtual std::size_t HandlEevent() = 0;
    virtual int Execute() = 0;
    sf::RenderWindow& GetWindow() { return m_window; }
  protected:
    IChildWindow() {}
    sf::RenderWindow m_window;
    sf::Event m_event;
  };
}

