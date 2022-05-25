#include "raylib.h"
#include "kpe_env.hpp"
#include "raymath.h"

#define SW (int)1280
#define SH (int)720

int main(void) {
    InitWindow(SW, SH, "");
    SetTargetFPS(60);
    
    auto *env = new kpe_env(SW, SH, {0.0, 1000.0});

    float t = 0.0f; 
    float h = 0.0f;

    while (!WindowShouldClose()) {

        t += GetFrameTime() * 50.0f;
        h += GetFrameTime() * 40.0f;
        if ( t > 1 ) {
            circle* o = env->create_circle({(double)SW/2 + (int(h * 50) % 100), SH/2 - 300}, 5);
            o->accelerate({0.0, 90000.0});
            Color col = ColorFromHSV(int(h * 2) % 350, 1.0f, 1.0f);
            o->r = col.r;
            o->g = col.g;
            o->b = col.b;
            t = 0.0f;
        }

        env->update_env(GetFrameTime());

        BeginDrawing();
        ClearBackground(BLACK);
        //DrawCircle(SW/2, SH/2, 350, BLACK);
        DrawRectangle(0, 0, 60, 20, WHITE);
        DrawFPS(0, 0);
            for (int i = 0; i < env->objects.size(); i++) {
                circle *obj = env->objects[i];
                //DrawCircle(obj->get_x(), obj->get_y(), 12, BLACK);
                Color col = {obj->r, obj->g, obj->b, 255};
                
                DrawCircle(obj->get_x(), obj->get_y(), 5, col);
                DrawRectangleLines(env->aabbs[i]->get_x(), env->aabbs[i]->get_y(), env->aabbs[i]->get_width(), env->aabbs[i]->get_height(), GREEN);
		    }
        EndDrawing();
    }
    env->~kpe_env();
    CloseWindow();
    
    return 0;
}