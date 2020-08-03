#pragma once
#include <SFML/Graphics.hpp>
#include "gui/gui-context.hpp"
namespace Havamal {
  class AppWin
  {
  public:
    AppWin();
    void Initialize();
    int Run();
    sf::Vector2f const GetSize() const;
    sf::RenderWindow& GetWindow();
    void SetContext(Gui::context_ptr& context) { m_gui_context = context; }
  private:
    std::size_t HandleEvent();
    void HandleKeyInput();
    sf::RenderWindow m_window;
    sf::Event m_event;
    std::shared_ptr<Gui::Context> m_gui_context;
  };
}

