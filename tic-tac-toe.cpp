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
    
    // Placemenet buttons for the player/user
    Button placementButton1{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {25, 15}, 0.30};
    Button placementButton2{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {180, 15}, 0.30};
    Button placementButton3{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {340, 15}, 0.30};
    Button placementButton4{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {25, 175}, 0.30};
    Button placementButton5{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {180, 175}, 0.30};
    Button placementButton6{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {340, 175}, 0.30};
    Button placementButton7{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {25, 330}, 0.30};
    Button placementButton8{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {180, 330}, 0.30};
    Button placementButton9{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {340, 330}, 0.30};
    bool exit = false;
    
    srand(time(NULL));

    int currentEnemyAttack = -1;
    int currentPlayerAttack = -1;
    bool playerAttacks[9] = {false};
    bool TakenFields[9] = {false};
    bool startGame = false;

    // Main game loop
    while (!WindowShouldClose() && !exit) {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (playButton.isPressed(mousePosition, mousePressed)) {
            startGame = true;
            int enemy_attack = rand() % 9;
            if(TakenFields[enemy_attack]){
                std::cout<<"Field Taken" << std::endl;
            }
            else{
                currentEnemyAttack = enemy_attack;
                TakenFields[enemy_attack] = true;
            }
        }

        if (exitButton.isPressed(mousePosition, mousePressed)) {
            exit = true;
        }
            if(placementButton1.isPressed(mousePosition, mousePressed)){
                if(TakenFields[0]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[0] = true;
                    TakenFields[0] = true;
                    int enemy_attack1 = rand() % 9;
                    while(TakenFields[enemy_attack1]){
                        enemy_attack1 = rand() % 9;
                    }
                    currentEnemyAttack = enemy_attack1;
                    TakenFields[enemy_attack1]= true;
                }
            }
            if(placementButton2.isPressed(mousePosition, mousePressed)){
                if(TakenFields[1]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[1] = true;
                    TakenFields[1] = true;
                    int enemy_attack2 = rand() % 9;
                    while(TakenFields[enemy_attack2]){
                        enemy_attack2 = rand() % 9;
                    }
                    currentEnemyAttack = enemy_attack2;
                    TakenFields[enemy_attack2]= true;
                }
            }
            if(placementButton3.isPressed(mousePosition, mousePressed)){
                if(TakenFields[2]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[2] = true;
                    TakenFields[2] = true;
                    int enemy_attack3 = rand() % 9;
                    while(TakenFields[enemy_attack3]){
                        enemy_attack3 = rand() % 9;
                    }
                    currentEnemyAttack = enemy_attack3;
                    TakenFields[enemy_attack3]= true;
                }
            }
            if(placementButton4.isPressed(mousePosition, mousePressed)){
                if(TakenFields[3]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[3] = true;
                    TakenFields[3] = true;
                    int enemy_attack4 = rand() % 9;
                    while(TakenFields[enemy_attack4]){
                        enemy_attack4 = rand() % 9;
                    }
                    currentEnemyAttack = enemy_attack4;
                    TakenFields[enemy_attack4]= true;
                }
            }
            if(placementButton5.isPressed(mousePosition, mousePressed)){
                if(TakenFields[4]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[4] = true;
                    TakenFields[4] = true;
                    int enemy_attack5 = rand() % 9;
                    while(TakenFields[enemy_attack5]){
                        enemy_attack5 = rand() % 9;
                    }
                    currentEnemyAttack = enemy_attack5;
                    TakenFields[enemy_attack5]= true;
                }
            }
            if(placementButton6.isPressed(mousePosition, mousePressed)){
                if(TakenFields[5]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[5] = true;
                    TakenFields[5] = true;
                    int enemy_attack6 = rand() % 9;
                    while(TakenFields[enemy_attack6]){
                        enemy_attack6 = rand() % 9;
                    }
                    currentEnemyAttack = enemy_attack6;
                    TakenFields[enemy_attack6]= true;
                }
            }
            if(placementButton7.isPressed(mousePosition, mousePressed)){
                if(TakenFields[6]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[6] = true;
                    TakenFields[6] = true;
                    int enemy_attack7 = rand() % 9;
                    while(TakenFields[enemy_attack7]){
                        enemy_attack7 = rand() % 9;
                    }
                    currentEnemyAttack = enemy_attack7;
                    TakenFields[enemy_attack7]= true;
                }
            }
            if(placementButton8.isPressed(mousePosition, mousePressed)){
                if(TakenFields[7]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[7] = true;
                    TakenFields[7] = true;
                    int enemy_attack8 = rand() % 9;
                    while(TakenFields[enemy_attack8]){
                        enemy_attack8 = rand() % 9;
                    }
                    currentEnemyAttack = enemy_attack8;
                    TakenFields[enemy_attack8]= true;
                }
            }
            if(placementButton9.isPressed(mousePosition, mousePressed)){
                if(TakenFields[8]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[8] = true;
                    TakenFields[8] = true;
                    int enemy_attack9 = rand() % 9;
                    while(TakenFields[enemy_attack9]){
                        enemy_attack9 = rand() % 9;
                    }
                    currentEnemyAttack = enemy_attack9;
                    TakenFields[enemy_attack9]= true;
                }
            }
            
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(playingGrid, 15, 15, WHITE);
        exitButton.Draw();
        playButton.Draw();
        placementButton1.Draw();
        placementButton2.Draw();
        placementButton3.Draw();
        placementButton4.Draw();
        placementButton5.Draw();
        placementButton6.Draw();
        placementButton7.Draw();
        placementButton8.Draw();
        placementButton9.Draw();

        // Player Attac Positions
        int PlayerXPos[9] = {50, 200, 350, 50, 200, 350, 50, 200, 350};
        int PlayerYPos[9] = {30, 30, 30, 190, 190, 190, 340, 340, 340};    

        for(int i=0; i<9; i++){
            if(playerAttacks[i]){
                Vector2 pos = {(float)PlayerXPos[i], (float)PlayerYPos[i]};
                DrawTextureEx(cross, pos, 0.0f, 0.25f, WHITE);
            }
        }    

        // Enemy Attack Positions
        if (currentEnemyAttack >= 0) {
            int EnemyXPos[9] = {50, 200, 350, 50, 200, 350, 50, 200, 350};
            int EnemyYPos[9] = {30, 30, 30, 190, 190, 190, 340, 340, 340};
            int EnemyDrawX;
            int EnemyDrawY;

            for(int EnemyXIndex = 0; EnemyXIndex<9; EnemyXIndex++){
                if(EnemyXIndex == currentEnemyAttack){
                    EnemyDrawX = EnemyXPos[EnemyXIndex];
                }
            }
            for(int EnemyYIndex = 0; EnemyYIndex<9; EnemyYIndex++){
                if (EnemyYIndex == currentEnemyAttack){
                    EnemyDrawY = EnemyYPos[EnemyYIndex];
                }
            }

            Vector2 pos = { static_cast<float>(EnemyDrawX), static_cast<float>(EnemyDrawY) };
            float scale = 0.25f;
            DrawTextureEx(circle, pos, 0.0f, scale, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
