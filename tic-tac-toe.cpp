#include"raylib.h"
#include<iostream>
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
    Button playButton{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/play-button.png",{20, 0}, 0.20};
    Button exitButton{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/exit-button.png", {500, 0}, 0.20};
    bool exit = false;

    // Main game loop
    while(!WindowShouldClose() && exit == false){
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if(playButton.isPressed(mousePosition, mousePressed)){
            std::cout<<"Start Button Pressed" << std::endl;
        }
        if(exitButton.isPressed(mousePosition, mousePressed)){
            exit = true;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);
        exitButton.Draw();
        playButton.Draw();
        DrawRectangle(113, 100, 5, 280, BLACK);
        DrawRectangle(206, 100, 5, 280, BLACK);
        DrawRectangle(20, 193, 280, 5, BLACK);
        DrawRectangle(20, 286, 280, 5, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}


