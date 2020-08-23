#include "AppWin.hpp"
#include "gui-factory.hpp"
Havamal::AppWin::AppWin()
  : m_window()
  , m_event()
  , m_gui_context()
  , m_scheme("theme.json")
  , m_clear_color(m_scheme["main_background"])
{
}

void Havamal::AppWin::Initialize()
{
  
  sf::Vector2u size = Config::ToVector<unsigned>(m_app_config["window"]["size"]);
  m_window.create(sf::VideoMode(size.x, size.y), "Havamal Editor");
}

int Havamal::AppWin::Execute()
{
  while (m_window.isOpen())
  {
    HandleEvent();
    m_window.clear(m_clear_color);
    m_window.draw(*m_gui_context);
    m_window.display();
  }
  return 0;
}

std::size_t Havamal::AppWin::HandleEvent()
{
  while (m_window.pollEvent(m_event))
  {
    switch (m_event.type)
    {
    case sf::Event::Closed:
      m_window.close();
      break;
    case sf::Event::KeyPressed:
    case sf::Event::KeyReleased:
      HandleKeyInput();
      break;

    }
  }
  return 0;
}

void Havamal::AppWin::HandleKeyInput()
{
  switch (m_event.key.code)
  {
  case sf::Keyboard::C:
    if (m_event.key.control)
      m_window.close();
    break;
  }
}

sf::Vector2f const Havamal::AppWin::GetSize() const
{
  return sf::Vector2f(m_window.getSize());
}

sf::RenderWindow& Havamal::AppWin::GetWindow()
{
  return m_window;
}
