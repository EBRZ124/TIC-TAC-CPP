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

    Texture2D background = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/background.png");
    Texture2D playingGrid = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/playingGrid.png");
    Button playButton{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/play-button.png",{524, 0}, 0.20};
    Button exitButton{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/exit-button.png", {592, 412}, 0.10};
    bool exit = false;

    // Main game loop
    while(!WindowShouldClose() && exit == false){
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if(playButton.isPressed(mousePosition, mousePressed)){
            srand(time(NULL));
            // int randomnumber = rand() % 2;
            int randomnumber = 0;
        }
        if(exitButton.isPressed(mousePosition, mousePressed)){
            exit = true;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(playingGrid, 15, 15, WHITE);
        exitButton.Draw();
        playButton.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}


