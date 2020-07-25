#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
  template<typename T, typename U>
  sf::Vector2<U> vector_cast(sf::Vector2<T> const& in_vec)
  {
    return sf::Vector2<U>(static_cast<U>(in_vec.x), static_cast<U>(in_vec.y));
  }
}