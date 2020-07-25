#pragma once
#include "gui-component.hpp"

namespace Gui {
  class Element :
    public Component
  {
  public:
    Element() {}
    virtual bool IsSelectable() const = 0;
    virtual ~Element();
  private:
    bool is_selectable;
  };
}