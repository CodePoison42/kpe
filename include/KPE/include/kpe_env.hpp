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
    void create_object(KPE_Vec2 pos);
    void update_env(float dt);
    void restrain_env();
    void update_positions(float dt);
    void apply_grav(float dt);
    ~kpe_env();
};

#endif