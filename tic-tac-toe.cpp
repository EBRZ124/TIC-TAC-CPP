#include"raylib.h"
#include<iostream>
#include<cstdlib>
#include"buttons.hpp"

void checkWin(int fields_taken_value[9], bool &playerWin, bool &enemyWin){
    playerWin = false;
    enemyWin = false;

    // Horizontal
    if(fields_taken_value[0]==fields_taken_value[1] && fields_taken_value[1]==fields_taken_value[2] && fields_taken_value[0] == 1) playerWin = true;
    if(fields_taken_value[3]==fields_taken_value[4] && fields_taken_value[4]==fields_taken_value[5] && fields_taken_value[3] == 1) playerWin = true;
    if(fields_taken_value[6]==fields_taken_value[7] && fields_taken_value[7]==fields_taken_value[8] && fields_taken_value[6] == 1) playerWin = true;
    if(fields_taken_value[0]==fields_taken_value[1] && fields_taken_value[1]==fields_taken_value[2] && fields_taken_value[0] == 2) enemyWin = true;
    if(fields_taken_value[3]==fields_taken_value[4] && fields_taken_value[4]==fields_taken_value[5] && fields_taken_value[3] == 2) enemyWin = true;
    if(fields_taken_value[6]==fields_taken_value[7] && fields_taken_value[7]==fields_taken_value[8] && fields_taken_value[6] == 2) enemyWin = true;

    // Vertical
    if(fields_taken_value[0]==fields_taken_value[3] && fields_taken_value[3]==fields_taken_value[6] && fields_taken_value[0] == 1) playerWin = true;
    if(fields_taken_value[1]==fields_taken_value[4] && fields_taken_value[4]==fields_taken_value[7] && fields_taken_value[1] == 1) playerWin = true;
    if(fields_taken_value[2]==fields_taken_value[5] && fields_taken_value[5]==fields_taken_value[8] && fields_taken_value[2] == 1) playerWin = true;
    if(fields_taken_value[0]==fields_taken_value[3] && fields_taken_value[3]==fields_taken_value[6] && fields_taken_value[0] == 2) enemyWin = true;
    if(fields_taken_value[1]==fields_taken_value[4] && fields_taken_value[4]==fields_taken_value[7] && fields_taken_value[1] == 2) enemyWin = true;
    if(fields_taken_value[2]==fields_taken_value[5] && fields_taken_value[5]==fields_taken_value[8] && fields_taken_value[2] == 2) enemyWin = true;

    // Diagonal
    if(fields_taken_value[0]==fields_taken_value[4] && fields_taken_value[4]==fields_taken_value[8] && fields_taken_value[0] == 1) playerWin = true;
    if(fields_taken_value[6]==fields_taken_value[4] && fields_taken_value[4]==fields_taken_value[2] && fields_taken_value[6] == 1) playerWin = true;
    if(fields_taken_value[0]==fields_taken_value[4] && fields_taken_value[4]==fields_taken_value[8] && fields_taken_value[0] == 2) enemyWin = true;
    if(fields_taken_value[6]==fields_taken_value[4] && fields_taken_value[4]==fields_taken_value[2] && fields_taken_value[6] == 2) enemyWin = true;
}


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
    Texture2D win_screen = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/player-win.png");
    Texture2D lose_screen = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/enemy-win.png");

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
    Button player_placement_buttons[9];
    player_placement_buttons[0] = Button("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {25, 15}, 0.3);  
    player_placement_buttons[1] = Button("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {180, 15}, 0.3);  
    player_placement_buttons[2] = Button("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {340, 15}, 0.3);  
    player_placement_buttons[3] = Button("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {25, 175}, 0.3);  
    player_placement_buttons[4] = Button("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {180, 175}, 0.3);  
    player_placement_buttons[5] = Button("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {340, 175}, 0.3);  
    player_placement_buttons[6] = Button("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {25, 330}, 0.3);  
    player_placement_buttons[7] = Button("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {180, 330}, 0.3);  
    player_placement_buttons[8] = Button("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/button-test.png", {340, 330}, 0.3);    

    bool exit = false;
    
    srand(time(NULL));

    // Number stuff
    int currentEnemyAttack = -1;
    int currentPlayerAttack = -1;
    double enemyMoveTime = 0;
    int pendingEnemyAttack = -1;
    int fields_taken_value[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; 

    // Win checking
    bool playerWin = false;
    bool enemyWin = false;

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
        for (int i = 0; i < 9; i++) {
            if (player_placement_buttons[i].isPressed(mousePosition, mousePressed)) {
                if (TakenFields[i]) {
                    std::cout << "Field Taken" << std::endl;
                } else {
                    playerAttacks[i] = true;
                    TakenFields[i] = true;
                    fields_taken_value[i] = 1;
                    checkWin(fields_taken_value, playerWin, enemyWin);

                    enemyThinking = true;
                    enemyMoveTime = GetTime() + 1.5;

                    showPlayerMoveIndicator = false;
                    showEnemyMoveIndicator = true;

                    int randomField = rand() % 9;
                    while (TakenFields[randomField]) {
                        randomField = rand() % 9;
                    }

                    pendingEnemyAttack = randomField;
                }
            }
        }
        BeginDrawing();
        for(int fieldButton=0; fieldButton<9; fieldButton++){
            player_placement_buttons[fieldButton].Draw();
        }

        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(playingGrid, 15, 15, WHITE);
        exitButton.Draw();
        playButton.Draw();

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
            fields_taken_value[pendingEnemyAttack] = 2;
            checkWin(fields_taken_value, playerWin, enemyWin);

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
        if(playerWin || enemyWin){
            enemyThinking = false;
            showPlayerMoveIndicator = false;
            showEnemyMoveIndicator = false;

            if(playerWin) DrawTexture(win_screen, 0, 0, WHITE);
            if(enemyWin) DrawTexture(lose_screen, 0, 0, WHITE);

        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
