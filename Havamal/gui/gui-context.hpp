#pragma once
#include <iterator>
#include "gui-container.hpp"
namespace Gui {
  class Context : public sf::Drawable
                , private sf::NonCopyable
  {
    using iterator = std::vector<container_ptr>::iterator;
  public:
    Context();
    virtual void Initialize();
    virtual void Update();
    virtual void HandleEvent(sf::Event&);
    virtual void AddContainer(iterator, iterator);
    virtual void AddContainer(container_ptr);
  private:
    std::vector<container_ptr> m_container;
    void draw(sf::RenderTarget&, sf::RenderStates) const {}
  };
}

