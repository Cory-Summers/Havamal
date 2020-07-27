#pragma once
#include <bitset>
#include <initializer_list>
#include <memory>
#include <vector>
#include "gui-id.hpp"
#include "gui-component.hpp"
#include "gui-element.hpp"
#include "sfml-util.hpp"
namespace Gui {
  class Factory;
  class Container : public Component
  {
    using const_ref = Container const&;
    friend Factory;
  public:
    Container() {}
    Container(std::initializer_list<component_ptr>&);

    const_ref operator=(std::initializer_list<component_ptr>&);
    virtual void        Initialize() {}
    virtual void        Update() {}
    virtual std::size_t Contains(sf::Vector2i) override;
            void        SetFill(sf::Vector2f const&, sf::Color const&);
    virtual void        SetSize(sf::Vector2f const& size);
    virtual sf::Vector2f Resize(sf::Vector2f) {}
    void ClearFill();
    virtual sf::Vector2f const& GetSize() const    { return m_size; }
    virtual std::size_t GetType() const { return static_cast<std::size_t>(ComponentID::Container); }
  protected:
    std::vector<std::shared_ptr<Component>>   m_components;
    std::unique_ptr<sf::RectangleShape>       m_background;
    sf::Vector2f m_size;
  private:
    void draw(sf::RenderTarget&, sf::RenderStates) const;
  };
  using container_ptr = std::shared_ptr<Container>;
}

