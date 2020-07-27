#include "gui/gui-context.hpp"

Gui::Context::Context()
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
  auto iter = begin;
  while (iter != end)
  {
    m_container.push_back(*iter);
    iter++;
  }
}

void Gui::Context::AddContainer(container_ptr ptr)
{
  m_container.push_back(ptr);
}
