#include "Bootstrapper.h"

std::shared_ptr<Havamal::AppWin> Havamal::Bootstrapper::Load(atom_float& progress, atom_bool& finished)
{
  std::shared_ptr<Havamal::AppWin> app_window = std::make_shared<Havamal::AppWin>();
  Gui::context_ptr context = Gui::Factory::CreateMainContext(app_window->GetWindow());
  app_window->SetContext(context);
  finished.store(true);
  return app_window;
}
