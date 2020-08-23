#include "gui-factory.hpp"
#include "AppWin.hpp"
namespace Havamal {
  std::shared_ptr<Gui::Container> Gui::Factory::MakeContainer(
    sf::Vector2f const& position,
    sf::Vector2f const& size,
    component_ptr parent,
    Gui::ColorScheme<generic_char> * scheme,
    std::initializer_list<component_ptr> elements)
  {
    sf::Color background((scheme != nullptr) ? (*scheme)[generic_string("element_background")] : sf::Color(0xFFFFFFFF));

    std::shared_ptr<Container> temp = std::make_shared<Container>(elements);
    temp->setPosition(position);
    temp->SetFill(size, background);
    temp->SetSize(size);
    temp->SetParent(parent);
    return temp;
  }

  std::shared_ptr<Gui::Context> Gui::Factory::CreateMainContext(AppWin& window)
  {
    sf::Vector2f window_size = sf::Vector2f(2560, 1440);
    std::shared_ptr<Context> context = std::make_shared<Context>(window.GetWindow());
    context->push_back(
      MakeContainer(
        { 0,0 },
        { window_size.x * .25f, window_size.y },
        component_ptr(),
        &window.GetScheme(),
        {}
        )
      );
    return context;
  }
}