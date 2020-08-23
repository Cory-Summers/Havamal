#include "gui-component.hpp"

sf::Transform Havamal::Gui::Component::GetGlobalTransform()
{
  sf::Transform global_transform = getTransform();
  auto* ptr = GetParent();
  while (ptr) {
    global_transform *= ptr->getTransform();
    ptr = ptr->GetParent();
  }
  return global_transform;
}
