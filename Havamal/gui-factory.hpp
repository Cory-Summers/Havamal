#pragma once
#include "gui/gui-container.hpp"
namespace Gui {
  class Factory
  {
  public:
    static std::shared_ptr<Container> MakeContainer(
      sf::Vector2f const & position, 
      sf::Vector2f const & size, 
      sf::Color color = sf::Color(0), 
      std::initializer_list<component_ptr> elements = std::initializer_list<component_ptr>());
  private:

  };
}
