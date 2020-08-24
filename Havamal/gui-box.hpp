#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include "gui-element.hpp"
namespace Havamal::Gui {
  class Box : public Gui::Element
  {
  public:
  private:
    std::unique_ptr<sf::Shape> m_shape;
  };
}

