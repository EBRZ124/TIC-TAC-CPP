#include"raylib.h"
#include<iostream>
#include<cstdlib>
#include"buttons.hpp"


int main()
{
    //--------------------------------------------------------------------------------------
    const int screenWidth = 680;
    const int screenHeight = 480;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - input actions");
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    Texture2D cross = LoadTexture("/Graphics/cross.png");
    Texture2D circle = LoadTexture("/Graphics/circle.png");
    Texture2D background = LoadTexture("/Graphics/background.png");
    Texture2D playingGrid = LoadTexture("/Graphics/playingGrid.png");
    Button playButton{"/Graphics/play-button.png",{524, 0}, 0.20};
    Button exitButton{"/Graphics/exit-button.png", {592, 412}, 0.10};
    bool exit = false;
    
    srand(time(NULL));

    int currentEnemyAttack = -1;
    int currentPlayerAttack = -1;

    // Main game loop
    while (!WindowShouldClose() && !exit) {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (playButton.isPressed(mousePosition, mousePressed)) {
            int enemy_attack = rand() % 9;
            currentEnemyAttack = enemy_attack;
        }

        if (exitButton.isPressed(mousePosition, mousePressed)) {
            exit = true;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(playingGrid, 15, 15, WHITE);
        exitButton.Draw();
        playButton.Draw();

        // Draw based on stored game state (not just when clicked)
        if (currentEnemyAttack >= 0) {
            int xPos[9] = {50, 200, 350, 50, 200, 350, 50, 200, 350};
            int yPos[9] = {30, 30, 30, 190, 190, 190, 340, 340, 340};
            
            int drawX = 350;
            int drawY = 30;
            Vector2 pos = { static_cast<float>(drawX), static_cast<float>(drawY) };
            float scale = 0.25f;
            DrawTextureEx(circle, pos, 0.0f, scale, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}


