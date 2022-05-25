#ifndef circle_hpp
#define circle_hpp

#include "object.hpp"
#include <math.h>

class circle : public object
{
protected:
    double radius;
    
public:
    circle(KPE_Vec2 pos, double radius);

    void set_radius(double r) { radius = r; }
    double get_radius() { return radius; }
    
    bool check_circle_collision(circle other_circle, double dist);
};


#endif