#include<iostream>
#include<cstdlib>
using namespace std;

void playing_field(string field[3][3], int play){
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

void display_field(string field[3][3]){
    for (int i=0; i<3; i++){
        cout << endl;
        for (int j=0; j<3; j++){
            cout << field[i][j];
        }
    }
}

int main(){

    srand(time(0));

    string field[3][3] = {
        {" A0 ", " A1 ", " A2 "},
        {" A3 ", " A4 ", " A5" },
        {" A6 ", " A7 ", " A8 "}
    };   

    display_field(field);

    // int randomnumber = rand() % 2;
    int randomnumber = 0;    

    if (randomnumber == 0){
        int player_attack;
        cout << endl << "Which A field do you want to attack: ";
        cin >> player_attack;
        if (player_attack > 8){
            cout << "Input a valid A number :";
            cin >> player_attack;
        }
        else{
            playing_field(field, player_attack);
            display_field(field);
        }
    }

    return 0;
}
