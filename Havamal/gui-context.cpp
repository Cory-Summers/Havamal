#include "gui/gui-context.hpp"
namespace Havamal {
  Gui::Context::Context()
  {
  }

  Gui::Context::Context(sf::RenderWindow& win)
    : parent_window(&win)
    , m_container()
  {
  }

  void Gui::Context::Initialize()
  {
  }

  void Gui::Context::Update()
  {
  }

  void Gui::Context::HandleEvent(sf::Event&)
  {
  }

  void Gui::Context::AddContainer(iterator begin, iterator end)
  {
    if (&(*begin) > & (*end)) throw;
    auto iter = begin;
    while (iter != end)
    {
      m_container.push_back(*iter);
      iter++;
    }
  }


  void Gui::Context::push_back(container_ptr ptr)
  {
    m_container.push_back(ptr);
  }

  void Gui::Context::draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
    for (auto& c : m_container)
      target.draw(*c);
  }
}