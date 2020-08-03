#pragma once
#include <atomic>
#include "gui-factory.hpp"
#include "AppWin.hpp"
namespace Havamal {
  class Bootstrapper
  {
    using atom_float = std::atomic<float>;
    using atom_bool = std::atomic<bool>;
  public:
    static std::shared_ptr<AppWin> Load(atom_float&, atom_bool&);
  private:
    Bootstrapper() {}
  };
};

