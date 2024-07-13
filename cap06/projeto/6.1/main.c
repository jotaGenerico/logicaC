#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GRAPH_SCALE 40

void drawAxes(void);
void drawFunction(double a, double b, double c);
void drawPoints(double a, double b, double c, double x1, double x2, double vertexX, double vertexY);
void drawInfo(double a, double b, double c, double x1, double x2, double vertexX, double vertexY);

int main(void) {
    double a, b, c;
    double discriminante, x1, x2, vertexX, vertexY;

    printf("Digite os coeficientes da função quadrática (ax^2 + bx + c):\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);

    // Cálculo do discriminante
    discriminante = b * b - 4 * a * c;

    // Cálculo das raízes
    if (discriminante >= 0) {
        x1 = (-b + sqrt(discriminante)) / (2 * a);
        x2 = (-b - sqrt(discriminante)) / (2 * a);
    } else {
        x1 = x2 = NAN;
    }

    // Cálculo do vértice
    vertexX = -b / (2 * a);
    vertexY = a * vertexX * vertexX + b * vertexX + c;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Gráfico da Função Quadrática");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        drawAxes();
        drawFunction(a, b, c);
        drawPoints(a, b, c, x1, x2, vertexX, vertexY);
        drawInfo(a, b, c, x1, x2, vertexX, vertexY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void drawAxes(void) {
    DrawLine(0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2, LIGHTGRAY);
    DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, LIGHTGRAY);

    // Desenhar marcações nos eixos
    for (int i = -10; i <= 10; i++) {
        if (i == 0) continue;
        int x = SCREEN_WIDTH / 2 + i * GRAPH_SCALE;
        int y = SCREEN_HEIGHT / 2 + i * GRAPH_SCALE;
        DrawLine(x, SCREEN_HEIGHT / 2 - 5, x, SCREEN_HEIGHT / 2 + 5, GRAY);
        DrawLine(SCREEN_WIDTH / 2 - 5, y, SCREEN_WIDTH / 2 + 5, y, GRAY);
        char num[5];
        sprintf(num, "%d", i);
        DrawText(num, x - 10, SCREEN_HEIGHT / 2 + 10, 10, GRAY);
        if (i != 0) DrawText(num, SCREEN_WIDTH / 2 + 10, y - 10, 10, GRAY);
    }
}

void drawFunction(double a, double b, double c) {
    for (int x = -SCREEN_WIDTH / 2; x < SCREEN_WIDTH / 2; x++) {
        double realX = (double)x / GRAPH_SCALE;
        double y = a * realX * realX + b * realX + c;
        int screenY = SCREEN_HEIGHT / 2 - (int)(y * GRAPH_SCALE);
        DrawPixel(x + SCREEN_WIDTH / 2, screenY, RED);
    }
}

void drawPoints(double a, double b, double c, double x1, double x2, double vertexX, double vertexY) {
    if (!isnan(x1)) {
        DrawCircle(SCREEN_WIDTH / 2 + (int)(x1 * GRAPH_SCALE), SCREEN_HEIGHT / 2, 5, BLUE);
        DrawCircle(SCREEN_WIDTH / 2 + (int)(x2 * GRAPH_SCALE), SCREEN_HEIGHT / 2, 5, BLUE);
    }
    DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - (int)(c * GRAPH_SCALE), 5, YELLOW);
    DrawCircle(SCREEN_WIDTH / 2 + (int)(vertexX * GRAPH_SCALE), SCREEN_HEIGHT / 2 - (int)(vertexY * GRAPH_SCALE), 5, GREEN);
}

void drawInfo(double a, double b, double c, double x1, double x2, double vertexX, double vertexY) {
    char info[100];
    sprintf(info, "a: %.2f", a);
    DrawText(info, 10, 10, 20, BLACK);
    sprintf(info, "b: %.2f", b);
    DrawText(info, 10, 40, 20, BLACK);
    sprintf(info, "c: %.2f", c);
    DrawText(info, 10, 70, 20, BLACK);

    if (!isnan(x1)) {
        sprintf(info, "Zeros: (%.2f, 0.00) e (%.2f, 0.00)", x1, x2);
        DrawText(info, 10, SCREEN_HEIGHT - 90, 20, BLUE);
    }

    sprintf(info, "(0.00, %.2f)", c);
    DrawText(info, 10, SCREEN_HEIGHT - 60, 20, YELLOW);

    sprintf(info, "Vértice: (%.2f, %.2f)", vertexX, vertexY);
    DrawText(info, 10, SCREEN_HEIGHT - 30, 20, GREEN);
}
