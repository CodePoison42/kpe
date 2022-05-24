#ifndef object_hpp
#define object_hpp

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
private:
    KPE_Vec2 current_pos;
    KPE_Vec2 old_pos;
    KPE_Vec2 acceleration;
public:
    int r, g, b; 
    object(KPE_Vec2 pos);
    double get_x();
    double get_y();
    void set_x(double x);
    void set_y(double y);
    void set_pos(KPE_Vec2 pos);
    KPE_Vec2 get_pos();
    void update_position(float dt);
    void accelerate(KPE_Vec2 accel);
};



#endif