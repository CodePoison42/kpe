#include "kpe_env.hpp"

kpe_env::kpe_env(float width, float height, KPE_Vec2 grvaity) {

}
void kpe_env::create_object(KPE_Vec2 pos) {
    objects.push_back(new object{pos});
}

void kpe_env::update_env(float dt) {
    apply_grav(dt);
    update_positions(dt);
    restrain_env();
}

void kpe_env::restrain_env() {
    const KPE_Vec2 pos{800.0, 450.0};
    const double radius = 200.0;
    for (auto &a : objects) {
        const KPE_Vec2 to_obj = {a->get_x() - pos.x, a->get_y() - pos.y};
        const double dist = sqrt(pow(to_obj.x, 2) + pow(to_obj.y, 2));
        // 50 is default
        if (dist > radius - 50) {
            const KPE_Vec2 n = to_obj + dist;
            a->set_pos(pos + n * (dist / 50.0));
            
        }
    }

}

void kpe_env::update_positions(float dt) {
    for (int a = 0; a < objects.size(); a++) {
        objects[a]->update_position(dt);
    }
    
}

void kpe_env::apply_grav(float dt) {
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->accelerate(gravity);
    }
    
}