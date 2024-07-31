#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int gameExit = 0;
class Tic_Tac_Toe
{
private:
    char yourSign = 'X';
    char comSign = 'O';
    char position[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

public:
    void checkResult(void);
    void printBody();
    void playGame(int);
    void placeSign(int, char);
};
// This function will check game result who won the game
void Tic_Tac_Toe::checkResult()
{
    if ((position[0] == 'X' && position[1] == 'X' && position[2] == 'X'))
    {
        cout << "\nCongrats! You won the game\n\n";
        exit(0);
    }
    else if ((position[0] == 'O' && position[1] == 'O' && position[2] == 'O'))
    {
        cout << "\nComputer won the game\n\n";
        exit(0);
    }
    else if ((position[3] == 'X' && position[4] == 'X' && position[5] == 'X'))
    {
        cout << "\nCongrats! You won the game\n\n";
        exit(0);
    }
    else if ((position[3] == 'O' && position[4] == 'O' && position[5] == 'O'))
    {
        cout << "\nComputer won the game\n\n";
        exit(0);
    }
    else if ((position[6] == 'X' && position[7] == 'X' && position[8] == 'X'))
    {
        cout << "\nCongrats! You won the game\n\n";
        exit(0);
    }
    else if ((position[6] == 'O' && position[7] == 'O' && position[8] == 'O'))
    {
        cout << "\nComputer won the game\n\n";
        exit(0);
    }
    else if ((position[0] == 'X' && position[4] == 'X' && position[8] == 'X'))
    {
        cout << "\nCongrats! You won the game\n\n";
        exit(0);
    }
    else if ((position[0] == 'O' && position[4] == 'O' && position[8] == 'O'))
    {
        cout << "\nComputer won the game\n\n";
        exit(0);
    }
    else if ((position[2] == 'X' && position[4] == 'X' && position[6] == 'X'))
    {
        cout << "\nCongrats! You won the game\n\n";
        exit(0);
    }
    else if ((position[2] == 'O' && position[4] == 'O' && position[6] == 'O'))
    {
        cout << "\nComputer won the game\n\n";
        exit(0);
    }
    else if ((position[0] == 'X' && position[3] == 'X' && position[6] == 'X'))
    {

        cout << "\nCongrats! You won the game\n\n";
        exit(0);
    }
    else if ((position[0] == 'O' && position[3] == 'O' && position[6] == 'O'))
    {
        cout << "\nComputer won the game\n\n";
        exit(0);
    }
    else if ((position[1] == 'X' && position[4] == 'X' && position[7] == 'X'))
    {
        cout << "\nCongrats! You won the game\n\n";
        exit(0);
    }
    else if ((position[1] == 'O' && position[4] == 'O' && position[7] == 'O'))
    {
        cout << "\nComputer won the game\n\n";
        exit(0);
    }
    else if ((position[2] == 'X' && position[5] == 'X' && position[8] == 'X'))
    {
        cout << "\nCongrats! You won the game\n\n";
        exit(0);
    }
    else if ((position[2] == 'O' && position[5] == 'O' && position[8] == 'O'))
    {
        cout << "\nComputer won the game\n\n";
        exit(0);
    }
    else
    {
        if (gameExit == 5)
        {
            cout << "\nGame is draw!\n\n";
            exit(0);
        }
    }
}
// This function will print the game body
void Tic_Tac_Toe::printBody()
{
    cout << "\n*******************" << endl;
    cout << "|  " << position[0] << "  |  " << position[1] << "  |  " << position[2] << "  |" << endl;
    cout << "|*****************|" << endl;
    cout << "|  " << position[3] << "  |  " << position[4] << "  |  " << position[5] << "  |" << endl;
    cout << "|*****************|" << endl;
    cout << "|  " << position[6] << "  |  " << position[7] << "  |  " << position[8] << "  |" << endl;
    cout << "*******************" << endl;
}
// This function will place player sign to given position
void Tic_Tac_Toe::placeSign(int pos, char sign)
{
    srand(time(0));
    repeat:
    pos = pos - 1;
    if (position[pos] == '1' && (position[pos] != 'O' && position[pos] != 'X'))
    {
        position[pos] = sign;
    }
    else if (position[pos] == '2' && (position[pos] != 'O' && position[pos] != 'X'))
    {
        position[pos] = sign;
    }
    else if (position[pos] == '3' && (position[pos] != 'O' && position[pos] != 'X'))
    {
        position[pos] = sign;
    }
    else if (position[pos] == '4' && (position[pos] != 'O' && position[pos] != 'X'))
    {
        position[pos] = sign;
    }
    else if (position[pos] == '5' && (position[pos] != 'O' && position[pos] != 'X'))
    {
        position[pos] = sign;
    }
    else if (position[pos] == '6' && (position[pos] != 'O' && position[pos] != 'X'))
    {
        position[pos] = sign;
    }
    else if (position[pos] == '7' && (position[pos] != 'O' && position[pos] != 'X'))
    {
        position[pos] = sign;
    }
    else if (position[pos] == '8' && (position[pos] != 'O' && position[pos] != 'X'))
    {
        position[pos] = sign;
    }
    else if (position[pos] == '9' && (position[pos] != 'O' && position[pos] != 'X'))
    {
        position[pos] = sign;
    }else
    {
        cout<<"\nInvalid position try again!\n";
        if (sign == 'X')
        {
            cin.sync();         
            cout << "\nChoose position to place your sign: ";
            cin >> pos;
            goto repeat;
        }else
        {
            cin.sync();         
            pos = rand() % 9;
            cout << "\nComputer chose " << pos << " position to place sign\n";            
            goto repeat;
        }               
    }
    
}
// This function will play the game
void Tic_Tac_Toe::playGame(int choose)
{
    int pos;
    srand(time(0));
    cout << "\nX is your sign and O is computer sign\n";
    printBody();
    if (choose == 1)
    {
        while (1)
        {
            gameExit++;
            cout << "\nChoose position to place your sign: ";
            cin >> pos;
            cin.sync();
            placeSign(pos, yourSign);
            printBody();
            checkResult();

            pos = rand() % 10;
            cout << "\nComputer chose " << pos << " position to place sign\n";
            placeSign(pos, comSign);
            printBody();
            checkResult();
        }
    }
    else
    {
        while (1)
        {
            gameExit++;
            pos = rand() % 10;
            cout << "\nComputer chose " << pos << " position to place sign\n";
            placeSign(pos, comSign);
            printBody();
            checkResult();

            cout << "\nEnter position to place your sign: ";
            cin >> pos;
            cin.sync();
            placeSign(pos, yourSign);
            printBody();
            checkResult();
        }
    }
}

int main()
{
    int choose;
    Tic_Tac_Toe t1;
    cout << "\n   -:  WELCOME TO TIC TAC TOE GAME  :-\n\n";
    cout << "Choose player turn" << endl;
    cout << "Press 1 for your turn\n"
         << "Press 2 for computer turn" << endl;
again:
    cin.sync();
    cin >> choose;
    if (choose == 1)
    {
        t1.playGame(choose);
    }
    else if (choose == 2)
    {
        t1.playGame(choose);
    }
    else
    {
        cout << "\nInvalid key pressed try again\n";
        goto again;
    }
    return 0;
}