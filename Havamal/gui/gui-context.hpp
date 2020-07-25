#pragma once
#include "gui-container.hpp"
namespace Gui {
  class Context : public sf::Drawable
                , private sf::NonCopyable
  {
  public:
  private:
    void draw(sf::RenderTarget&, sf::RenderStates) const {}
  };
}

