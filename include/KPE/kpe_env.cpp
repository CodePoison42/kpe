#include "kpe_env.hpp"

kpe_env::kpe_env(float width, float height, KPE_Vec2 grav) : gravity(grav), width(width), height(height) {
}
kpe_env::~kpe_env(){
    for (int i = 0; i < objects.size(); i++) {
        delete objects[i];
        objects.erase(objects.begin() + i);
    }
    
}

circle *kpe_env::create_circle(KPE_Vec2 pos, double radius) {
    circle *o = new circle{ pos, radius};
    objects.push_back(o);
    aabbs.push_back(&o->bounding_box);
    return o;
}

void kpe_env::update_env(float dt) {
    const float sub_updates = 10; // TODO: EXPOSE TO DEV
    const float sub_dt = dt / sub_updates;
    for (int i = sub_updates; i > 0; i--) {
        apply_grav();
        restrain_env();
        solve_collisions();
        update_positions(sub_dt);
        update_aabb();
    }
}

void kpe_env::apply_grav() {
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->accelerate(gravity);
    }   
}

void kpe_env::restrain_env() {
    for (auto &a : objects) {
      
        if (a->get_x() > (width - a->get_radius())) {
		    a->set_x(2 * (width - a->get_radius()) - a->get_x());
		    a->set_accel(a->get_vel());
        // a hits the left boundary:
        } else if (a->get_x() < a->get_radius()) {
            a->set_x(2 * a->get_radius() - a->get_x());
            a->set_accel(a->get_vel());
        }
        // a hits the bottom boundary:
        if (a->get_y() > (height - a->get_radius())) {
            a->set_y(2 * (height - a->get_radius()) - a->get_y());
            a->set_accel(a->get_vel());

        // a hits the top boundary:
        } else if (a->get_y() < 5) {
            a->set_y(2 * a->get_radius() - a->get_y());
            a->set_accel(a->get_vel());
        }
        
    }
}

void kpe_env::solve_collisions() {
    //const int object_count = objects.size();
    for (int a = 0; a < objects.size(); a++) {
        circle *object_1 = objects[a];
        for (int b = a+1; b < objects.size(); b++) {
            circle *object_2 = objects[b];
            if (object_1->bounding_box.check_aabb_collision(object_2->bounding_box)){

                const KPE_Vec2 col_axis = object_1->get_pos() - object_2->get_pos();
                const double dist = sqrt(pow((object_1->get_x() - object_2->get_x()),2) + pow((object_1->get_y() - object_2->get_y()), 2));
                if (object_1->check_circle_collision(*object_2, dist)) {
                    const KPE_Vec2 n = col_axis / dist;
                    const double delta = 10.0 - dist;
                    object_1->set_pos(object_1->get_pos() + 0.5 * delta * n);
                    object_2->set_pos(object_2->get_pos() - 0.5 * delta * n);
                }

            }
        }
    }
}

void kpe_env::update_positions(float dt) {
    for (int a = 0; a < objects.size(); a++) {
        objects[a]->update_position(dt);
    }   
}

void kpe_env::update_aabb() {
    for (int i = 0; i < aabbs.size(); i++) {
        aabbs[i]->set_xy(objects[i]->get_x() - (objects[i]->get_radius() * 1.8f), objects[i]->get_y() - (objects[i]->get_radius()* 1.8f));
    }
}
