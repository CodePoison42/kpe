#include "raylib.h"
#include "kpe_env.hpp"
#include "raymath.h"

#define SW 1280
#define SH 720

int main(void) {
    InitWindow(SW, SH, "");
    SetTargetFPS(60);
    
    auto *env = new kpe_env(SW, SH, {0.0, 1000.0});

    float t = 0; 
    float h = 0;

    while (!WindowShouldClose()) {

        t += GetFrameTime() * 50;
        h += GetFrameTime() * 20;
        if ( t > 1 ) {
            object* o = env->create_object({SW/2 + (double)GetRandomValue(-50, 50), SH/2 + 100});
            Color col = ColorFromHSV(int(h * 3) % 350, 1.0f, 1.0f);
            o->r = col.r;
            o->g = col.g;
            o->b = col.b;
            t = 0;
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