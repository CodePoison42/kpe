#ifndef object_hpp
#define object_hpp

#include "aabb.hpp"
#include <vector>


struct KPE_Vec2
{
    double x, y;
};


KPE_Vec2 operator+(KPE_Vec2 const& v1, KPE_Vec2 const& v2);
KPE_Vec2 operator-(KPE_Vec2 const& v1, KPE_Vec2 const& v2);
KPE_Vec2 operator/(KPE_Vec2 const& v1, KPE_Vec2 const& v2);
KPE_Vec2 operator/(KPE_Vec2 const& v1, double const& v2);
KPE_Vec2 operator*(KPE_Vec2 const& v1, KPE_Vec2 const& v2);
KPE_Vec2 operator*(double const& v1, KPE_Vec2 const& v2);
KPE_Vec2 operator*(KPE_Vec2 const& v1, double const& v2);

class object
{
protected:
    KPE_Vec2 current_pos;
    KPE_Vec2 old_pos;
    KPE_Vec2 acceleration;
    KPE_Vec2 velocity;
    
public:
    unsigned char r, g, b, a; 
    object(KPE_Vec2 pos);

    double get_x() { return current_pos.x; }
    double get_y() { return current_pos.y; }
    KPE_Vec2 get_pos() { return current_pos; }
    KPE_Vec2 get_accel() { return acceleration; }
    KPE_Vec2 get_vel() { return velocity; }

    void set_x(double x) { current_pos.x = x; }
    void set_y(double y) { current_pos.y = y; }
    void set_pos(KPE_Vec2 pos) { current_pos = pos; }
    void set_accel(KPE_Vec2 accel) { acceleration = accel; }
    void set_vel(KPE_Vec2 vel) { velocity = vel; }
    
    void update_position(float dt);
    void accelerate(KPE_Vec2 accel);

    aabb bounding_box;
};



#endif