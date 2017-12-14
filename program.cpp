#include <iostream>

using namespace std;

void introMessage();
void printTable(char tictoe[]);
void changeValue(int value);
void confirmMove(char ttChoice[], char selection);

void CheckWins(char ttChoice[]);

int positionsFilled = 0;

int main()
{

    char tictoeChoice[9]; //row 1 (0-2), row 2 (3-5), row 3 (7-8)

    for(int i = 0 ; i < 9; i++)
    {
        tictoeChoice[i] = '0' + i;
        
    }

    introMessage();
    printTable(tictoeChoice);

    char continueGame = 'n';
    int position = 0;
    char choice = 'n';

    do{


        if(position == 0)
        {
            cout << "Player 1's turn!" << endl;
            confirmMove(tictoeChoice, 'X');
        }
        else if(position == 1)
        {
            cout << "Player 2's turn!" << endl;
            confirmMove(tictoeChoice, 'O');
        }

        printTable(tictoeChoice);

        

        // cout << "\n\nType q or Q to quit the game (Anything else will continue): " << endl;
        // cin >> continueGame;
        position++;
        if(position > 1)
        {
            position = 0;
        }
    }
    while(0 == 0);
    //while(continueGame != 'q' && continueGame != 'Q');

    cout << "You have decided to exit this game." << endl;

    return 0;
}

void CheckWins(char ttChoice[])
{

    // 0,1,2
    // 0,3,6
    // 0,4,8
    if(
        (ttChoice[0] == ttChoice[1] && ttChoice[1]== ttChoice[2])||
        (ttChoice[0] == ttChoice[3] && ttChoice[3]== ttChoice[6])||
        (ttChoice[0] == ttChoice[4] && ttChoice[4]== ttChoice[8]) )
    {

        cout << "Player using: " << ttChoice[0] << ", you won!" << endl;
        printTable(ttChoice);
        exit(EXIT_SUCCESS);
    }

    // 1,4,7
    // 2,4,6
    // 3,4,5

    if(
        (ttChoice[1] == ttChoice[4] && ttChoice[4]== ttChoice[7])||
        (ttChoice[2] == ttChoice[4] && ttChoice[4]== ttChoice[6])||
        (ttChoice[3] == ttChoice[4] && ttChoice[4]== ttChoice[5]) )
    {

        cout << "Player using: " << ttChoice[1] << ", you won!" << endl;
        printTable(ttChoice);
        exit(EXIT_SUCCESS);
    }


    // 6,7,8
    // 2,5,8
    if(
        (ttChoice[6] == ttChoice[7] && ttChoice[7]== ttChoice[8])||
        (ttChoice[2] == ttChoice[5] && ttChoice[5]== ttChoice[8]) )
    {

        cout << "Player using: " << ttChoice[6] << ", you won!" << endl;
        printTable(ttChoice);
        exit(EXIT_SUCCESS);
    }
    
}

void confirmMove(char ttChoice[], char selection)
{

    int positionSelect = -1;

    do{
        cout << "Please select an empty position [NUMBER (0-8)] from the table." << endl;

        //This is to avoid an infinite loop in case a number is not entered!
        //Found answer on stack over flow!
        while(!(cin >> positionSelect))
        {
            cout << "Input was incorrect, please try again..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        if(positionSelect < 0 || positionSelect > 8){
            cout << "The number must be between 0 and 8!" << endl;
        }else{

            if(ttChoice[positionSelect] == 'X' || ttChoice[positionSelect] == 'O')
            {
                cout << "This choice has already been selected. Try another position from the table." <<endl;
                positionSelect = -1;
            }

        }

    }while(positionSelect < 0 || positionSelect > 8);


    //cout << "You entered position: " << positionSelect << " and tic or toe: " << ticOrToe << endl;

    ttChoice[positionSelect] = selection;
    positionsFilled++;

    CheckWins(ttChoice);

    if(positionsFilled >= 9)
    {
        //CHECK FOR A WIN HERE
        cout << "It's a draw!" << endl;
        exit(EXIT_SUCCESS);

    }

    
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