#include "circles.hpp"

circle::circle(KPE_Vec2 pos, double _radius) : object( pos ), radius(_radius)
{bounding_box = aabb(pos.x - _radius, pos.y - _radius, _radius*2,  _radius*2);}

bool circle::check_circle_collision(circle other_circle, double dist) {
    if (dist < radius + other_circle.get_radius())
        return true;
    return false;
}