#pragma once
#include "gui/gui-context.hpp"
namespace Gui {
  class Factory
  {
  public:
    static std::shared_ptr<Container> MakeContainer(
      sf::Vector2f const& position,
      sf::Vector2f const& size,
      component_ptr m_parent = component_ptr(),
      sf::Color color = sf::Color(0), 
      std::initializer_list<component_ptr> elements = std::initializer_list<component_ptr>());
    static std::shared_ptr<Context> CreateMainContext(sf::RenderWindow&);
  private:

  };
}
