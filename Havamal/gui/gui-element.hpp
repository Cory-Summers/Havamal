#pragma once
#include <nlohmann/json.hpp>
#include "gui-component.hpp"
#include "../application-settings.hpp"
namespace Havamal::Gui {
  class Element :
    public Component
  {
  public:
    Element() {}
    virtual bool LoadFromJSON(generic_string const&) = 0;
    bool IsSelectable() const { return is_selectable; }
    virtual ~Element() = 0;
  private:
    bool is_selectable = false;
  };
}