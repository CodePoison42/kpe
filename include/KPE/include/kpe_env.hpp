#ifndef kpe_env_hpp
#define kpe_env_hpp


#include "circles.hpp"
#include <math.h>


class kpe_env
{
protected:
    KPE_Vec2 gravity = {0.0, 1000.0};
    float width, height;
public:
    std::vector<aabb*> aabbs;
    std::vector<circle*> objects;
    kpe_env(float width, float height, KPE_Vec2 grvaity);
    ~kpe_env();
    
    circle *create_circle(KPE_Vec2 pos, double radius);

    void update_env(float dt);
    
    void apply_grav();
    void restrain_env();
    void solve_collisions();
    void update_positions(float dt);
};

#endif