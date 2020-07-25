#include "gui-factory.hpp"

std::shared_ptr<Gui::Container> Gui::Factory::MakeContainer(
  sf::Vector2f const& position, 
  sf::Vector2f const& size, 
  sf::Color color, 
  std::initializer_list<component_ptr> elements)
{
  std::shared_ptr<Container> temp = std::make_shared<Container>(elements);
  temp->setPosition(position);
  temp->SetFill(size, color);

}
