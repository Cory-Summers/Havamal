#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
namespace Gui {
  /* Base interface for GUI classes*/
  class Component : public sf::Drawable
                  , public sf::Transformable
  {
  public:
    virtual void          Initialize() = 0; 
    virtual void          Update() = 0;
    virtual sf::Vector2f  Resize(sf::Vector2f) = 0;
    virtual std::size_t   Contains(sf::Vector2i) { return 0; }
    virtual std::size_t   GetType() const = 0;
    virtual bool          IsActive() const { return is_active; }
    virtual void          Activate()   { is_active = true; }
    virtual void          Deactivate() { is_active = false; }
    virtual sf::Transform GetGlobalTransform();
    Component const*      GetParent() const { return m_parent.lock().get(); }
    virtual void          SetParent(std::shared_ptr<Gui::Component>& parent) { m_parent = parent; }
  private:
    bool is_active = false;
    std::weak_ptr<Component> m_parent;
  };
  using component_ptr = std::shared_ptr<Gui::Component>;
}

