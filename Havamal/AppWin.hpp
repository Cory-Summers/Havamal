#pragma once
#include <SFML/Graphics.hpp>
#include "gui/gui-context.hpp"
namespace Havamal {
  class AppWin
  {
  public:
    AppWin();
    int Run();
    void HandleEvent();
  private:
    sf::RenderWindow m_window;
    sf::Event m_event;
    std::shared_ptr<Gui::Context> m_gui_context;
  };
}

