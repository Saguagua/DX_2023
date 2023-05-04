#include "framework.h"
#include "Vector2.h"

int Vector2::ManhettenDistance(const Vector2& other) const
{
    
    return abs(other.x - x) + abs(other.y - y);
}
