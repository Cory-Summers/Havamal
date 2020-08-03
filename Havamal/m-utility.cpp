#include "m-utility.hpp"

sf::Vector2f Util::CenterObject(sf::FloatRect const& rect, sf::Vector2f const& frame)
{
  return sf::Vector2f({
    (frame.x - rect.width) / 2.0f,
    (frame.y - rect.height) / 2.0f
  })
    ;
}