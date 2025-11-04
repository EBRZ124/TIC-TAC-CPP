#include<iostream>
#include<cstdlib>
using namespace std;

void win_checker(string field[3][3], bool &checker){
    checker = false;
    bool player = false;
    bool opponent = false;

    // Horizontal X
    if(field[0][0]==field[0][1] && field[0][1]==field[0][2] && field[0][0] == "  X "){ player = true;}
    if(field[1][0]==field[1][1] && field[1][1]==field[1][2] && field[1][0] == "  X "){ player = true;}
    if(field[2][0]==field[2][1] && field[2][1]==field[2][2] && field[2][0] == "  X "){ player = true;}
    // Horizontal O
    if(field[0][0]==field[0][1] && field[0][1]==field[0][2] && field[0][0] == "  O "){ opponent = true;}
    if(field[1][0]==field[1][1] && field[1][1]==field[1][2] && field[1][0] == "  O "){ opponent = true;}
    if(field[2][0]==field[2][1] && field[2][1]==field[2][2] && field[2][0] == "  O "){ opponent = true;}
    // Vertical X
    if(field[0][0]==field[1][0] && field[1][0]==field[2][0] && field[0][0] == "  X "){ player = true;}
    if(field[0][1]==field[1][1] && field[1][1]==field[2][1] && field[0][1] == "  X "){ player = true;}
    if(field[0][2]==field[1][2] && field[1][2]==field[2][2] && field[0][2] == "  X "){ player = true;}
    // Vertical O
    if(field[0][0]==field[1][0] && field[1][0]==field[2][0] && field[0][0] == "  O "){ opponent = true;}
    if(field[0][1]==field[1][1] && field[1][1]==field[2][1] && field[0][1] == "  O "){ opponent = true;}
    if(field[0][2]==field[1][2] && field[1][2]==field[2][2] && field[0][2] == "  O "){ opponent = true;}
    // Diagonal X
    if(field[0][0]==field[1][1] && field[1][1]==field[2][2] && field[0][0] == "  X "){ player = true;}
    if(field[1][2]==field[1][1] && field[1][1]==field[0][2] && field[1][2] == "  X "){ player = true;}
    // Diagonal O
    if(field[0][0]==field[1][1] && field[1][1]==field[2][2] && field[0][0] == "  O "){ opponent = true;}
    if(field[1][2]==field[1][1] && field[1][1]==field[0][2] && field[1][2] == "  O "){ opponent = true;}
    
    if(player){
        cout << "You won!" << endl;
        checker = true;
    } 
    else if(opponent){
        cout << "Opponent has won" << endl;
        checker = true;
    }
    else{
        cout << "No one has won yet" << endl;
    }

}

void player_attack_field(string field[3][3], int play){
    int number = 0;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(number == play){
            field[i][j] = "  X ";
        }
            number++;
        }
     }
}

bool check_if_field_empty(string field[3][3], int attack){
    int checker = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if (checker == attack){
                if(field[i][j] == "  X " || field[i][j] == "  O "){
                    return false;
                }
                else{
                    return true;
                }
            }
        checker++;
        }
    }
    return false;
}

void enemy_attack_field(string field[3][3], int enemy_play){
    int number = 0;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(number == enemy_play){
            field[i][j] = "  O ";
        }
            number++;
        }
     }
}

void display_field(string field[3][3]){
    for (int i=0; i<3; i++){
        cout << endl;
        for (int j=0; j<3; j++){
            cout << field[i][j];
        }
    }
    cout << endl;
}

int main(){

    bool win = false;

    string field[3][3] = {
        {" A0 ", " A1 ", " A2 "},
        {" A3 ", " A4 ", " A5" },
        {" A6 ", " A7 ", " A8 "}
    };

    srand(time(NULL)); 
    display_field(field);

    while(!win){
        //int randomnumber = rand() % 2;
        int randomnumber = 0;

        // Player goes first
        if(randomnumber == 0){

            // Players move (first)
            int player_attack;
            cout << endl << "Which A field do you want to attack: A";
            cin >> player_attack;

            while (player_attack < 0 || player_attack > 8) {
                cout << "Input a valid A number: A";
                cin >> player_attack;
            }
            while (!check_if_field_empty(field, player_attack)) {
                cout << "Field already taken, enter a valid number: A";
                cin >> player_attack;
                cout << endl;
            }
            player_attack_field(field, player_attack);
            display_field(field);
            cout << endl;

            win_checker(field, win);
            if (win) break;

            // Opponents move
            cout << endl << "Enemy's attack: " << endl;
            int enemy_attack1 = rand() % 9;

            while (!check_if_field_empty(field, enemy_attack1)) {
                enemy_attack1 = rand() % 9;
            }
            enemy_attack_field(field, enemy_attack1);
            display_field(field);
            cout << endl;

            win_checker(field, win);
            if (win) break;
        }

        // Opponent goes first
        else if(randomnumber == 1){
            //Opponent
            cout << endl << "Enemy's attack: " << endl;
            int enemy_attack1 = rand() % 9;

            while (!check_if_field_empty(field, enemy_attack1)) {
                enemy_attack1 = rand() % 9;
            }

            enemy_attack_field(field, enemy_attack1);
            display_field(field);
            cout << endl;

            win_checker(field, win);
            if (win) break;

            // Player
            int player_attack;
            cout << endl << "Which A field do you want to attack: A";
            cin >> player_attack;

            while (player_attack < 0 || player_attack > 8) {
                cout << "Input a valid A number: A";
                cin >> player_attack;
            }

            while (!check_if_field_empty(field, player_attack)) {
                cout << "Field already taken, enter a valid number: A";
                cin >> player_attack;
                cout << endl;
            }

            player_attack_field(field, player_attack);
            display_field(field);
            cout << endl;

            win_checker(field, win);
            if (win) break;
        }
    }
    return 0;
}
