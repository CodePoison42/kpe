#include "raylib.h"
#include "kpe_env.hpp"
#include "raymath.h"

#define SW 1280
#define SH 720

int main(void) {
    InitWindow(SW, SH, "");
    SetTargetFPS(60);
    
    auto *env = new kpe_env(SW, SH, {0.0, 1000.0});

    float t = 0.0f; 
    float h = 0.0f;

    while (!WindowShouldClose()) {

        t += GetFrameTime() * 50.0f;
        h += GetFrameTime() * 40.0f;
        if ( t > 5 ) {
            object* o = env->create_object({SW/2 + (double)GetRandomValue(-20, 20), SH/2 - 300});
            o->accelerate({0.0, 90000.0});
            Color col = ColorFromHSV(int(h * 2) % 350, 1.0f, 1.0f);
            o->r = col.r;
            o->g = col.g;
            o->b = col.b;
            t = 0.0f;
        }

        env->update_env(GetFrameTime());

        BeginDrawing();
        ClearBackground(GRAY);
        DrawCircle(SW/2, SH/2, 350, BLACK);
        DrawFPS(0, 0);
            for (int i = 0; i < env->objects.size(); i++) {
			    object *obj = env->objects[i];
                //DrawCircle(obj->get_x(), obj->get_y(), 12, BLACK);
                Color col = {obj->r, obj->g, obj->b, 255};
			    DrawCircle(obj->get_x(), obj->get_y(), 10, col);
		    }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}