#pragma once
#include "gui/gui-context.hpp"
#include "ColorScheme.h"
namespace Havamal { class AppWin; }
namespace Havamal::Gui {
  class Factory
  {
  public:
    static std::shared_ptr<Container> MakeContainer(
      sf::Vector2f const& position,
      sf::Vector2f const& size,
      component_ptr m_parent = component_ptr(),
      ColorScheme<generic_char>* color_scheme = nullptr,
      std::initializer_list<component_ptr> elements = std::initializer_list<component_ptr>());
    static std::shared_ptr<Context> CreateMainContext(Havamal::AppWin &);
  private:

  };
}
