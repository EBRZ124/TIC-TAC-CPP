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
    Texture2D enemy_move_indicator = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/enemys-move.png");
    Texture2D players_move_indicator = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/your-move.png");
    Vector2 move_indicator_pos = {(float)540, (float)70};

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
    double enemyMoveTime = 0;
    int pendingEnemyAttack = -1;

    //booleans
    bool playerAttacks[9] = {false};
    bool enemyAttacks[9] = { false };
    bool TakenFields[9] = {false};
    bool showEnemyMoveIndicator = false;
    bool showPlayerMoveIndicator = false;
    bool enemyThinking = false;
    bool startGame = false;

    // Main game loop
    while (!WindowShouldClose() && !exit) {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (playButton.isPressed(mousePosition, mousePressed)) {
            startGame = true;
            showEnemyMoveIndicator = true;
            enemyThinking = true;
            enemyMoveTime = GetTime() + 1.5;

            int randomField = rand() % 9;
            while(TakenFields[randomField]){
                randomField = rand() % 9;
            }
            pendingEnemyAttack = randomField;
        }

        if (exitButton.isPressed(mousePosition, mousePressed)) {
            exit = true;
        }
            
            // PLayers attacks
            if(placementButton1.isPressed(mousePosition, mousePressed)){
                if(TakenFields[0]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[0] = true;
                    TakenFields[0] = true;

                    enemyThinking = true;
                    enemyMoveTime = GetTime() + 1.5;

                    showPlayerMoveIndicator = false;
                    showEnemyMoveIndicator = true;

                    int randomField = rand() % 9;
                    while(TakenFields[randomField]){
                        randomField = rand() % 9;
                    }
                    pendingEnemyAttack = randomField;
                    
                }
            }
            if(placementButton2.isPressed(mousePosition, mousePressed)){
                if(TakenFields[1]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[1] = true;
                    TakenFields[1] = true;

                    enemyThinking = true;
                    enemyMoveTime = GetTime() + 1.5;

                    showPlayerMoveIndicator = false;
                    showEnemyMoveIndicator = true;

                    int randomField = rand() % 9;
                    while(TakenFields[randomField]){
                        randomField = rand() % 9;
                    }
                    pendingEnemyAttack = randomField;
                }
            }
            if(placementButton3.isPressed(mousePosition, mousePressed)){
                if(TakenFields[2]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[2] = true;
                    TakenFields[2] = true;

                    enemyThinking = true;
                    enemyMoveTime = GetTime() + 1.5;

                    showPlayerMoveIndicator = false;
                    showEnemyMoveIndicator = true;

                    int randomField = rand() % 9;
                    while(TakenFields[randomField]){
                        randomField = rand() % 9;
                    }
                    pendingEnemyAttack = randomField;
                }
            }
            if(placementButton4.isPressed(mousePosition, mousePressed)){
                if(TakenFields[3]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[3] = true;
                    TakenFields[3] = true;

                    enemyThinking = true;
                    enemyMoveTime = GetTime() + 1.5;

                    int randomField = rand() % 9;
                    while(TakenFields[randomField]){
                        randomField = rand() % 9;
                    }
                    pendingEnemyAttack = randomField;
                }
            }
            if(placementButton5.isPressed(mousePosition, mousePressed)){
                if(TakenFields[4]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[4] = true;
                    TakenFields[4] = true;

                    enemyThinking = true;
                    enemyMoveTime = GetTime() + 1.5;

                    showPlayerMoveIndicator = false;
                    showEnemyMoveIndicator = true;

                    int randomField = rand() % 9;
                    while(TakenFields[randomField]){
                        randomField = rand() % 9;
                    }
                    pendingEnemyAttack = randomField;
                }
            }
            if(placementButton6.isPressed(mousePosition, mousePressed)){
                if(TakenFields[5]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[5] = true;
                    TakenFields[5] = true;

                    enemyThinking = true;
                    enemyMoveTime = GetTime() + 1.5;

                    showPlayerMoveIndicator = false;
                    showEnemyMoveIndicator = true;

                    int randomField = rand() % 9;
                    while(TakenFields[randomField]){
                        randomField = rand() % 9;
                    }
                    pendingEnemyAttack = randomField;
                }
            }
            if(placementButton7.isPressed(mousePosition, mousePressed)){
                if(TakenFields[6]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[6] = true;
                    TakenFields[6] = true;

                    enemyThinking = true;
                    enemyMoveTime = GetTime() + 1.5;

                    showPlayerMoveIndicator = false;
                    showEnemyMoveIndicator = true;

                    int randomField = rand() % 9;
                    while(TakenFields[randomField]){
                        randomField = rand() % 9;
                    }
                    pendingEnemyAttack = randomField;
                }
            }
            if(placementButton8.isPressed(mousePosition, mousePressed)){
                if(TakenFields[7]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[7] = true;
                    TakenFields[7] = true;

                    enemyThinking = true;
                    enemyMoveTime = GetTime() + 1.5;

                    showPlayerMoveIndicator = false;
                    showEnemyMoveIndicator = true;

                    int randomField = rand() % 9;
                    while(TakenFields[randomField]){
                        randomField = rand() % 9;
                    }
                    pendingEnemyAttack = randomField;
                }
            }
            if(placementButton9.isPressed(mousePosition, mousePressed)){
                if(TakenFields[8]){
                    std::cout<<"Field Taken";
                } else {
                    playerAttacks[8] = true;
                    TakenFields[8] = true;

                    enemyThinking = true;
                    enemyMoveTime = GetTime() + 1.5;

                    showPlayerMoveIndicator = false;
                    showEnemyMoveIndicator = true;

                    int randomField = rand() % 9;
                    while(TakenFields[randomField]){
                        randomField = rand() % 9;
                    }
                    pendingEnemyAttack = randomField;
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

        if(showEnemyMoveIndicator){
            DrawTextureEx(enemy_move_indicator, move_indicator_pos, 0.0f, 0.15f, WHITE);
        }
        if(showPlayerMoveIndicator){
            DrawTextureEx(players_move_indicator, move_indicator_pos, 0.0f, 0.15f, WHITE);
        }

        // Player Attac Positions
        int PlayerXPos[9] = {50, 200, 350, 50, 200, 350, 50, 200, 350};
        int PlayerYPos[9] = {30, 30, 30, 190, 190, 190, 340, 340, 340};    

        for(int i=0; i<9; i++){
            if(playerAttacks[i]){
                Vector2 crossPos = {(float)PlayerXPos[i], (float)PlayerYPos[i]};
                DrawTextureEx(cross, crossPos, 0.0f, 0.25f, WHITE);
            }
        }    

        if(enemyThinking && GetTime() >= enemyMoveTime){
            enemyAttacks[pendingEnemyAttack] = true;
            TakenFields[pendingEnemyAttack] = true;
            currentEnemyAttack = pendingEnemyAttack;

            enemyThinking = false;
            pendingEnemyAttack = -1;

            showEnemyMoveIndicator = false;
            showPlayerMoveIndicator = true;
        }

        // Enemy Attack Positions
        if (currentEnemyAttack >= 0) {
            int EnemyXPos[9] = {50, 200, 350, 50, 200, 350, 50, 200, 350};
            int EnemyYPos[9] = {30, 30, 30, 190, 190, 190, 340, 340, 340};
            int EnemyDrawX;
            int EnemyDrawY;

            for(int i=0; i<9; i++){
                if(enemyAttacks[i]){
                    Vector2 circlePos = {(float)EnemyXPos[i], (float)EnemyYPos[i]};
                    DrawTextureEx(circle, circlePos, 0.0f, 0.25f, WHITE);
                }
            }   
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
