#include "AppWin.hpp"
#include "gui-factory.hpp"
Havamal::AppWin::AppWin()
  : m_window(sf::VideoMode(2560, 1440), "Havamal")
  , m_event()
  , m_gui_context(Gui::Factory::CreateMainContext(m_window))
{
}

int Havamal::AppWin::Run()
{
  while (m_window.isOpen())
  {

  }
  return 0;
}
