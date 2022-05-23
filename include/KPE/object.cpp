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
KPE_Vec2 operator*(KPE_Vec2 const& v1, double const& v2) {
    return KPE_Vec2{v1.x * v2,  v1.y * v2};
}

object::object(KPE_Vec2 pos): current_pos(pos), old_pos(pos) {}

void object::update_position(float dt) {
    const KPE_Vec2 vel = current_pos - old_pos;

    //save pos to now be old when next update
    old_pos = current_pos;

    //verlet ingration https://en.wikipedia.org/wiki/Verlet_integration
    current_pos = current_pos + vel + acceleration * dt * dt;

    //clear accel
    acceleration = KPE_Vec2{};
}
void object::accelerate(KPE_Vec2 accel) {
    acceleration = acceleration + accel;
}
double object::get_x() {
    return current_pos.x;
}
double object::get_y() {
    return current_pos.y;
}
void object::set_x(double x) {
    current_pos.x = x;
}
void object::set_y(double y) {
    current_pos.y = y;
}
void object::set_pos(KPE_Vec2 pos) {
    current_pos = pos;
}
KPE_Vec2 object::get_pos() {
    return current_pos;
}