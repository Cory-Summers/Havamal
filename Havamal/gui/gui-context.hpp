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
    Context(sf::RenderWindow&);
    virtual void Initialize();
    virtual void Update();
    virtual void HandleEvent(sf::Event&);
    virtual void AddContainer(iterator, iterator);
    virtual void push_back(container_ptr);
  private:
    sf::RenderWindow* parent_window;
    std::vector<container_ptr> m_container;
    void draw(sf::RenderTarget&, sf::RenderStates) const;
  };
  using context_ptr = std::shared_ptr<Context>;
}

