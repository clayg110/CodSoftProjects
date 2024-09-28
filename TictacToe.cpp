#include <iostream>
#include <vector>

using namespace std;

class TicTacToe
{
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe()
    {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }
    void printBoard()
    {
        cout << "Current Board:\n";
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << board[i][j];
                if (j < 2)
                    cout << " | ";
            }
            cout << endl;
            if (i < 2)
                cout << "---------\n";
        }
        cout << endl;
    }
    bool placeMark(int row, int col)
    {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }
    bool checkWin()
    {
        for (int i = 0; i < 3; ++i)
        {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            {
                return true; // Win found
            }
        }
        return (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
               (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer);
    }
    void switchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    void play()
    {
        int row, col;
        for (int turn = 0; turn < 9; ++turn)
        {
            printBoard();
            cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
            cin >> row >> col;
            while (!placeMark(row, col))
            {
                cout << "Invalid move! Try again: ";
                cin >> row >> col;
            }
            if (checkWin())
            {
                printBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                return;
            }
            switchPlayer();
        }
        printBoard();
        cout << "It's a draw!\n";
    }
};

int main()
{
    TicTacToe game;
    game.play();
    return 0;
}