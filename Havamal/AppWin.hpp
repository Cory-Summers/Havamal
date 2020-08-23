#pragma once
#include <SFML/Graphics.hpp>
#include "application-settings.hpp"
#include "gui/gui-context.hpp"
#include "config-manager.hpp"
#include "ColorScheme.h"
namespace Havamal {
  class Bootstrapper;
  class AppWin
  {
  public:
    AppWin();
    void Initialize();
    int Execute();
    sf::Vector2f const GetSize() const;
    sf::RenderWindow& GetWindow();
    Gui::ColorScheme<generic_char>& GetScheme() { return m_scheme; }
    void SetContext(Gui::context_ptr& context) { m_gui_context = context; }
  private:
    std::size_t HandleEvent();
    void HandleKeyInput();
    sf::RenderWindow m_window;
    sf::Event m_event;
    Gui::ColorScheme<generic_char> m_scheme;
    sf::Color m_clear_color;
    std::shared_ptr<Gui::Context> m_gui_context;

    Config::Manager<generic_char> m_app_config;
    friend class Bootstrapper;
  };
}

