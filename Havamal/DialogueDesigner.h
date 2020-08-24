#pragma once
#include "child-window-interface.hpp"
namespace Havamal {
  namespace Dialogue {
    class DesignerWindow : public IChildWindow
    {
    public:
      DesignerWindow();
      void Initialize();
      std::size_t Update();
      std::size_t HandleEvent();
      int Execute();
    private:

    };
  }
};

