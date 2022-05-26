#include "object.hpp"


KPE_Vec2 operator+(KPE_Vec2 const& v1, KPE_Vec2 const& v2) {
    return KPE_Vec2{v1.x + v2.x, v1.y + v2.y};
}
KPE_Vec2 operator-(KPE_Vec2 const& v1, KPE_Vec2 const& v2) {
    return KPE_Vec2{v1.x - v2.x, v1.y - v2.y};
}
KPE_Vec2 operator/(KPE_Vec2 const& v1, KPE_Vec2 const& v2) {
    return KPE_Vec2{v1.x / v2.x, v1.y / v2.y};
}
KPE_Vec2 operator/(KPE_Vec2 const& v1, double const& v2) {
    return KPE_Vec2{v1.x / v2, v1.y / v2};
}
KPE_Vec2 operator*(KPE_Vec2 const& v1, KPE_Vec2 const& v2) {
    return KPE_Vec2{v1.x * v2.x, v1.y * v2.y};
}
KPE_Vec2 operator*(double const& v1, KPE_Vec2 const& v2) {
    return KPE_Vec2{v1 * v2.x, v1 * v2.y};
}
KPE_Vec2 operator*(KPE_Vec2 const& v1, double const& v2) {
    return KPE_Vec2{v1.x * v2,  v1.y * v2};
}

object::object(KPE_Vec2 pos): current_pos(pos), old_pos(pos), bounding_box({0, 0, 0, 0})
{}

void object::update_position(float dt) {
    velocity = current_pos - old_pos;

    //save pos to now be old when next update
    old_pos = current_pos;

    //verlet ingration https://en.wikipedia.org/wiki/Verlet_integration
    current_pos = current_pos + velocity + acceleration * dt * dt;

    //clear accel
    acceleration = KPE_Vec2{};
}

void object::accelerate(KPE_Vec2 accel) {
    acceleration = acceleration + accel;
}


