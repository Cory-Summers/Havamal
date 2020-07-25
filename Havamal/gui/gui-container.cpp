#include "gui-container.hpp"

Gui::Container::Container(std::initializer_list<Component>& list)
  : m_components()
{
  for (auto& c : list)
    m_components.emplace_back(std::make_shared<Component>(c));
}
Gui::Container const& Gui::Container::operator=(std::initializer_list<component_ptr>& list)
{
  for (auto& c : list)
    m_components.push_back(c);
  return *this;
}
Gui::Container::Container(std::initializer_list<std::shared_ptr<Component>>& list)
  : m_components()
{
  Activate();
  for (auto& c : list)
    m_components.push_back(c);
}

int Gui::Container::Contains(sf::Vector2i pos)
{
  const std::size_t vec_size = m_components.size();
  const sf::FloatRect rect(getPosition(), m_size);
  if (rect.contains(sf::vector_cast<int, float>(pos)))
  {
    for (std::size_t i = 0; i < vec_size; ++i)
    {
      if(m_components[i]->Contains(pos))
    }
    return 1;
  }
  return 0;
}

void Gui::Container::SetFill(sf::Vector2f const& size , sf::Color const& color)
{
  m_size = size;
  m_background = std::make_unique<sf::RectangleShape>(m_size);
  m_background->setFillColor(color);
}

void Gui::Container::ClearFill()
{
  m_background.release();
}

void Gui::Container::SetSize(sf::Vector2f const& size)
{
  m_background->setSize(size);
  m_size = size;
}

void Gui::Container::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  if (m_background)
    target.draw(*m_background, states);
  for (const auto& c : m_components)
    target.draw(*c, states);
}
