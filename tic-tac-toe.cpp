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
    // PLaying elements
    Texture2D cross = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/cross.png");
    Texture2D circle = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/circle.png");

    // Big textures
    Texture2D background = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/background.png");
    Texture2D playingGrid = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/playingGrid.png");
    
    // Buttons
    Button playButton{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/play-button.png",{524, 0}, 0.20};
    Button exitButton{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/exit-button.png", {592, 412}, 0.10};
    Button placementButton1{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {15, 15}, 0.30};
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

        if(placementButton1.isPressed(mousePosition, mousePressed)){
            int player_attack = 0;
            currentPlayerAttack = player_attack;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(playingGrid, 15, 15, WHITE);
        exitButton.Draw();
        playButton.Draw();
        placementButton1.Draw();

        if (currentEnemyAttack >= 0) {
            int xPos[9] = {50, 200, 350, 50, 200, 350, 50, 200, 350};
            int yPos[9] = {30, 30, 30, 190, 190, 190, 340, 340, 340};
            int drawX;
            int drawY;

            for(int xIndex = 0; xIndex<9; xIndex++){
                if(xIndex == currentEnemyAttack){
                    drawX = xPos[xIndex];
                }
            }
            for(int yIndex = 0; yIndex<9; yIndex++){
                if (yIndex == currentEnemyAttack){
                    drawY = yPos[yIndex];
                }
            }

            Vector2 pos = { static_cast<float>(drawX), static_cast<float>(drawY) };
            float scale = 0.25f;
            DrawTextureEx(circle, pos, 0.0f, scale, WHITE);
        }

        if (currentPlayerAttack >= 0) {
            int xPos[9] = {50, 200, 350, 50, 200, 350, 50, 200, 350};
            int yPos[9] = {30, 30, 30, 190, 190, 190, 340, 340, 340};
            int drawX;
            int drawY;

            for(int xIndex = 0; xIndex<9; xIndex++){
                if(xIndex == currentEnemyAttack){
                    drawX = xPos[xIndex];
                }
            }
            for(int yIndex = 0; yIndex<9; yIndex++){
                if (yIndex == currentEnemyAttack){
                    drawY = yPos[yIndex];
                }
            }

            Vector2 pos = { static_cast<float>(drawX), static_cast<float>(drawY) };
            float scale = 0.25f;
            DrawTextureEx(cross, pos, 0.0f, scale, WHITE);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}


