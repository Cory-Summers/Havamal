#include "gui-container.hpp"

Havamal::Gui::Container const& Havamal::Gui::Container::operator=(std::initializer_list<component_ptr>& list)
{
  for (auto& c : list)
    m_components.push_back(c);
  return *this;
}
Havamal::Gui::Container::Container(std::initializer_list<std::shared_ptr<Component>>& list)
  : m_components()
  , m_background()
  , m_size()
{
  Activate();
  for (auto& c : list)
    m_components.push_back(c);
}

std::size_t Havamal::Gui::Container::Contains(sf::Vector2i pos)
{
  const std::size_t vec_size = m_components.size();
  const sf::FloatRect rect(getPosition(), m_size);
  if (rect.contains(sf::vector_cast<int, float>(pos)))
  {
    for (std::size_t i = 0; i < vec_size; ++i)
    {
      if (m_components[i]->Contains(pos))
        return (i + 1);
    }
    return 1;
  }
  return 0;
}

void Havamal::Gui::Container::SetFill(sf::Vector2f const& size, sf::Color const& color)
{
  m_size = size;
  m_background = std::make_unique<sf::RectangleShape>(m_size);
  m_background->setFillColor(color);
}

void Havamal::Gui::Container::ClearFill()
{
  m_background.release();
}

void Havamal::Gui::Container::SetSize(sf::Vector2f const& size)
{
  if(m_background)
    m_background->setSize(size);
  m_size = size;
}

void Havamal::Gui::Container::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  if (m_background)
    target.draw(*m_background, states);
  for (const auto& c : m_components)
    target.draw(*c, states);
}
