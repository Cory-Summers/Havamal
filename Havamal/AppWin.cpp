#include "AppWin.hpp"
#include "gui-factory.hpp"
Havamal::AppWin::AppWin()
  : m_window()
  , m_event()
  , m_gui_context()
{
}

void Havamal::AppWin::Initialize()
{
  m_window.create(sf::VideoMode(2560, 1440), "Havamal Editor");
}

int Havamal::AppWin::Run()
{
  while (m_window.isOpen())
  {
    HandleEvent();
    m_window.clear({ 17, 17, 17 });
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
