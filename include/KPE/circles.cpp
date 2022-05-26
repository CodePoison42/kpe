#include "circles.hpp"

circle::circle(KPE_Vec2 pos, double _radius) : object( pos ), radius(_radius)
{double size = _radius * 1.8f; bounding_box = aabb(pos.x - size, pos.y - size, size*2, size*2);}

bool circle::check_circle_collision(circle other_circle, double dist) {
    if (dist < radius + other_circle.get_radius())
        return true;
    return false;
}