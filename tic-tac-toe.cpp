#include"raylib.h"
#include<iostream>
#include<cstdlib>
#include"buttons.hpp"

void checkWin(int fields_taken_value[9], bool &playerWin, bool &enemyWin, bool &playerDraw){
    playerWin = false;
    enemyWin = false;
    playerDraw = false;

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
    // ---------------------------------------- MISC ----------------------------------------
    const int screenWidth = 680;
    const int screenHeight = 480;
    InitAudioDevice();
    InitWindow(screenWidth, screenHeight, "raylib [core] example - input actions");
    SetTargetFPS(60);

    // PLaying elements
    Texture2D cross = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/cross.png");
    Texture2D circle = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/circle.png");
    Texture2D win_screen = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/player-win.png");
    Texture2D lose_screen = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/enemy-win.png");
    Texture2D draw_screen = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/player-draw.png");

    // Sounds
    Sound crossSFX = LoadSound("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Sounds/cross-sound.wav");
    Sound circleSFX = LoadSound("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Sounds/circle-sound.wav");
    Sound winningSFX = LoadSound("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Sounds/win_sound.ogg");
    Sound loseSFX = LoadSound("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Sounds/lose-sound.wav");
    Sound drawSFX = LoadSound("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Sounds/draw-sound.wav");
    Music BGM1 = LoadMusicStream("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Sounds/background-music-1.mp3");

    // Big textures
    Texture2D background = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/background.png");
    Texture2D playingGrid = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/playingGrid.png");
    Texture2D enemy_move_indicator = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/enemys-move.png");
    Texture2D players_move_indicator = LoadTexture("/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/your-move.png");
    Vector2 move_indicator_pos = {(float)540, (float)70};

    // Buttons
    Button playButton{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/play-button.png",{524, 0}, 0.20};
    Button exitButton{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/exit-button.png", {592, 412}, 0.10};
    Button retryButton{"/Users/evaldsberzins/raylib/projects/tic-tac-toe/Graphics/rety-button.png", {272, 350}, 0.2};
    
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
    int to_draw_counter = 0;

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
    bool player_turn = false;
    bool playerDraw = false;
    bool startGame = false;

    // Sound booleans
    bool playedWinSound = false;
    bool playedLoseSound = false;
    bool playedDrawSound = false;
    bool playingMusic = true;

    if(playingMusic){
        PlayMusicStream(BGM1);
    }


    // ---------------------------------------- Main game loop ----------------------------------------
    while (!WindowShouldClose() && !exit) {
        if(playingMusic){
            UpdateMusicStream(BGM1);
        }
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

        BeginDrawing();
        ClearBackground(BLACK);
        for(int fieldButton=0; fieldButton<9; fieldButton++){
            player_placement_buttons[fieldButton].Draw();
        }
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

        if(player_turn){
        for (int i = 0; i < 9; i++) {
                if (player_placement_buttons[i].isPressed(mousePosition, mousePressed)) {
                    if (TakenFields[i]) {
                        std::cout << "Field Taken" << std::endl;
                    } else {
                        playerAttacks[i] = true;
                        PlaySound(crossSFX);
                        TakenFields[i] = true;
                        fields_taken_value[i] = 1;
                        to_draw_counter++;

                        checkWin(fields_taken_value, playerWin, enemyWin, playerDraw);

                        player_turn = false;
                        enemyThinking = true;
                        enemyMoveTime = GetTime() + 1.5;

                        showPlayerMoveIndicator = false;
                        showEnemyMoveIndicator = true;

                        int randomField = rand() % 9;
                        while (TakenFields[randomField]) {
                            randomField = rand() % 9;
                        }

                        pendingEnemyAttack = randomField;
                        break;
                    }
                }
            }
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

            currentEnemyAttack = pendingEnemyAttack;
            PlaySound(circleSFX);

            enemyThinking = false;
            pendingEnemyAttack = -1;

            player_turn = true;

            showEnemyMoveIndicator = false;
            showPlayerMoveIndicator = true;
            to_draw_counter ++;

            checkWin(fields_taken_value, playerWin, enemyWin, playerDraw);
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
        if(to_draw_counter == 9) playerDraw = true;
        if(playerWin || enemyWin || playerDraw){
            enemyThinking = false;
            showPlayerMoveIndicator = false;
            showEnemyMoveIndicator = false;

            if(playerWin) {
                DrawTexture(win_screen, 0, 0, WHITE);
                playingMusic = false;
                if(!playedWinSound){
                    PlaySound(winningSFX);
                    playedWinSound = true;
                }
                retryButton.Draw();
            }
            if(playerDraw) {
                DrawTexture(draw_screen, 0, 0, WHITE);
                playingMusic = false;
                if(!playedDrawSound){
                    PlaySound(drawSFX);
                    playedDrawSound = true;
                }
                retryButton.Draw();
            }
            if(enemyWin) {
                DrawTexture(lose_screen, 0, 0, WHITE);
                playingMusic = false;
                if(!playedLoseSound){
                    PlaySound(loseSFX);
                    playedLoseSound = true;
                }
                retryButton.Draw();
            }

            if(playerWin || enemyWin || playerDraw){
                retryButton.Draw();
                if(retryButton.isPressed(mousePosition, mousePressed)){
                    for(int i=0; i<9; i++){
                        TakenFields[i] = false;
                        fields_taken_value[i] = 0;
                        playerAttacks[i] = false;
                        enemyAttacks[i] = false;
                    }
                    playerWin = false;
                    enemyWin = false;
                    playerDraw = false;

                    playedWinSound = false;
                    playedDrawSound = false;
                    playedLoseSound = false;

                    startGame = false;
                    player_turn = false;
                    enemyThinking = false;
                    pendingEnemyAttack = -1;
                    currentEnemyAttack = -1;
                    currentPlayerAttack = -1;

                    showEnemyMoveIndicator = false;
                    showPlayerMoveIndicator = false;

                    StopMusicStream(BGM1);
                    playingMusic = true;
                    PlayMusicStream(BGM1);

                    to_draw_counter = 0;
                }
            }
        }
        EndDrawing();
    }
    UnloadMusicStream(BGM1);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
