#include "Bootstrapper.h"

std::shared_ptr<Havamal::AppWin> Havamal::Bootstrapper::Load(atom_float& progress, atom_bool& finished)
{
  std::shared_ptr<Havamal::AppWin> app_window = std::make_shared<Havamal::AppWin>();
  Gui::context_ptr context = Gui::Factory::CreateMainContext(*app_window);
  app_window->SetContext(context);
  app_window->m_app_config = Havamal::Config::Manager(generic_string("app_config.json"));
  finished.store(true);
  return app_window;
}
