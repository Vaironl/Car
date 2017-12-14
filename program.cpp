#include <iostream>

using namespace std;

void introMessage();
void printTable(char tictoe[]);

void changeValue(int value);

int main()
{

    char tictoeChoice[9]; //row 1 (0-2), row 2 (3-5), row 3 (7-8)

    for(int i = 0 ; i < 9; i++)
    {
        tictoeChoice[i] = ' ';
        
    }

    introMessage();
    printTable(tictoeChoice);

    char quit = 'n';

    do{

    }
    while(quit == 'n' || quit == 'N');

    cout << "You have decided to exit this game." << endl;

    return 0;
}

void printTable(char tictoe[])
{
    int position = 0;
    cout << "|---|---|---|" << endl;
    cout << "| " << tictoe[position] << " | " << tictoe[++position] << " | " << tictoe[++position] << " |" << endl;
    cout << "|---|---|---|" << endl;
    cout << "| " << tictoe[++position] << " | " << tictoe[++position] << " | " << tictoe[++position] << " |" << endl;
    cout << "|---|---|---|" << endl;
    cout << "| " << tictoe[++position] << " | " << tictoe[++position] << " | " << tictoe[++position] << " |" << endl;
    cout << "|___|___|___|" << endl;
    cout << "" << endl;


    cout << "================" << endl;
}

void introMessage(){
    cout << "Welcome new player!" << endl;
    cout << "This game is meant to be a tic tac toe game." << endl;
    cout << "DEBUGGING OUTPUT HERE" << endl;
    cout << "================" << endl;
}