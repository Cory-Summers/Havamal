#pragma once
#include "child-window-interface.hpp"
namespace Havamal {
  template<class parent_type = IChildWindow>
  class IStrategy
  {
  public:
    enum Class Type
    {
      None
    };
    struct Context 
    {
      parent_type * parent;
    };
  public:
    virtual std::size_t Update() = 0;
    virtual std::size_t HandleEvent(sf::Event&) = 0;
    Type const& GetType() const { return m_type; }
    Context const& GetContext() const { return m_context; }
  private:
    const Type m_type = Type::None;
    Context m_context;
  };
}

