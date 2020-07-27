#include "gui-factory.hpp"

std::shared_ptr<Gui::Container> Gui::Factory::MakeContainer(
  sf::Vector2f const& position, 
  sf::Vector2f const& size,
  component_ptr parent,
  sf::Color color, 
  std::initializer_list<component_ptr> elements)
{
  std::shared_ptr<Container> temp = std::make_shared<Container>(elements);
  temp->setPosition(position);
  temp->SetFill(size, color);
  temp->SetParent(parent);

}

std::shared_ptr<Gui::Context> Gui::Factory::CreateMainContext(sf::RenderWindow& window)
{
  std::shared_ptr<Context> context = std::make_shared<Context>();
  return context;
}
