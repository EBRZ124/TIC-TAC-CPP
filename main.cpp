#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    string field[3][3] = {
        {" A1 ", " A1 ", " A1 "},
        {" A2 ", " A2 ", " A2" },
        {" A3 ", " A3 ", " A3 "}
    };

    for (int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout<<field[i][j];
        }
    }

return 0;
}