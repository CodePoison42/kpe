#include "kpe_env.hpp"

kpe_env::kpe_env(float width, float height, KPE_Vec2 grvaity) {

}
object *kpe_env::create_object(KPE_Vec2 pos) {
    object *o = new object{pos};;
    objects.push_back(o);
    return o;
}

void kpe_env::update_env(float dt) {
    const float sub_updates = 5; // TODO: EXPOSE TO DEV
    const float sub_dt = dt / sub_updates;
    for (int i = sub_updates; i > 0; i--) {
        apply_grav();
        restrain_env();
        solve_collisions();
        update_positions(sub_dt);
    }
}

void kpe_env::apply_grav() {
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->accelerate(gravity);
    }
    
}

void kpe_env::restrain_env() {
    const KPE_Vec2 pos{640.0, 360.0};
    const double radius = 350.0 - 10.0;
    for (auto &a : objects) {
        if (sqrt(pow((pos.x - a->get_x()),2) + pow((pos.y - a->get_y()), 2)) > radius) {
            KPE_Vec2 dist = {a->get_x() - pos.x, a->get_y() - pos.y};

                        
            dist = dist * radius / (sqrt(pow((pos.x - a->get_x()),2) + pow((pos.y - a->get_y()), 2)) );
            //dist.y *= 250.0f / (sqrtf(powf((RockLmao.x - Player1.body->getX()),2) + powf((RockLmao.y - Player1.body->getY()), 2)) /*- 210*/);
                        
            a->set_pos(pos + dist);
        }
    }
}

void kpe_env::solve_collisions() {
    const int object_count = objects.size();
    for (int a = 0; a < objects.size(); a++) {
        object *object_1 = objects[a];
        for (int b = a+1; b < objects.size(); b++) {
            object *object_2 = objects[b];
            const KPE_Vec2 col_axis = object_1->get_pos() - object_2->get_pos();
            const double dist = sqrt(pow((object_1->get_x() - object_2->get_x()),2) + pow((object_1->get_y() - object_2->get_y()), 2));
            if (dist < 20.0) {
                const KPE_Vec2 n = col_axis / dist;
                const double delta = 20.0 - dist;
                object_1->set_pos(object_1->get_pos() + 0.5 * delta * n);
                object_2->set_pos(object_2->get_pos() - 0.5 * delta * n);
            }

        }

    }
}

void kpe_env::update_positions(float dt) {
    for (int a = 0; a < objects.size(); a++) {
        objects[a]->update_position(dt);
    }
    
}

