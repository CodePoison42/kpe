#include "raylib.h"
#include "kpe_env.hpp"
#include "raymath.h"

#define SW 1280
#define SH 720

int main(void) {
    InitWindow(SW, SH, "");
    SetTargetFPS(60);
    
    auto *env = new kpe_env(SW, SH, {0.0, 1000.0});

    for (int i = 0; i < 10; i++) {
		env->create_object({SW/2, SH/2});
	}

    while (!WindowShouldClose()) {

        
        env->update_env(GetFrameTime());

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(0, 0);
            for (int i = 0; i < env->objects.size(); i++) {
			    object *obj = env->objects[i];
			    DrawCircle(obj->get_x(), obj->get_y(), 5, RED);
		    }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}