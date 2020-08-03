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
  temp->SetSize(size);
  temp->SetParent(parent);
  return temp;
}

std::shared_ptr<Gui::Context> Gui::Factory::CreateMainContext(sf::RenderWindow& window)
{
  sf::Vector2f window_size = sf::Vector2f(2560, 1440);
  std::shared_ptr<Context> context = std::make_shared<Context>(window);
  context->push_back(
    MakeContainer(
      { 0,0 },
      { window_size.x * .25f, window_size.y },
      component_ptr(),
      sf::Color(255, 37, 37),
      {}
  )
  );
  return context;
}
