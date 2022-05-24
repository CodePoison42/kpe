#ifndef kpe_env_hpp
#define kpe_env_hpp

#include "object.hpp"
#include <math.h>


class kpe_env
{
private:
    KPE_Vec2 gravity = {0.0, 1000.0};
public:
    std::vector<object*> objects;
    kpe_env(float width, float height, KPE_Vec2 grvaity);
    
    object *create_object(KPE_Vec2 pos);

    void update_env(float dt);
    
    void apply_grav();
    void restrain_env();
    void solve_collisions();
    void update_positions(float dt);
    
    
    ~kpe_env();
};

#endif