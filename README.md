# TIC-TAC-CPP
Simple text-based Tic Tac Toe game made in c++

The GUI is made using Raylib library: https://github.com/raysan5/raylib 

## Gameplay

There is background music and additional sound effects, but to experience those, you must play the actual game.

### Winning scenario

![Image](https://github.com/user-attachments/assets/585237fa-bfbf-4f5f-a0cc-6325515b6e49)

### Losing scenario

![Image](https://github.com/user-attachments/assets/e673cfac-b473-4f59-86ae-d7ba4535b523)

### Draw scenario

![Image](https://github.com/user-attachments/assets/aa9fef86-b35c-4807-a4f4-02f79337364e)

## Files

tic-tac-toe.cpp - main file from which the program can be built and ran with a graphical interface

buttons.hpp - object for buttons

buttons.cpp - button logic and functions

    .
    ├── Scrap - folder with the primitive version of the game
    │   ├── main.cpp - primitive version which has the logic and algorithms and can be used seperately to play the game, but with no GUI
    ├── Graphics - folder with visual elements for the GUI
  

## WIP

- Replayability - currently the game can only be played once and has to be clsoed and reopened for a new game

- Volume control - a settings menu where audio levels can be adjusted

- Be able to play as either the cross or the circle

- Choose weather or not to start first, second or random

- Difficulty settings
