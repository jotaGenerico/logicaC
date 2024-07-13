#include "raylib.h"

int main(void)
{

    // Inicialize a janela
    InitWindow(800, 600, "Hello, Raylib!");

    // Loop principal
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, Raylib!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    // Feche a janela ao finalizar
    CloseWindow();

    return 0;
}
