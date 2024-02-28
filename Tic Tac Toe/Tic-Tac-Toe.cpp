#include<iostream>
using namespace std;

class TickTacToe {
public:
    char matrix[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'}, 
        {'-', '-', '-'}
                        };
    bool player1Turn = true;
    char player1Symbol;
    char player2Symbol;
    bool gameEnd = false;
    int won = -1;

    bool check(){
        // Check rows
        for(int i = 0; i < 3; i++){
            if(matrix[i][0] != '-' && matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]){
                cout << "Player " << (matrix[i][0] == player1Symbol ? 1 : 2) << " Won!" << endl;
                return true;
            }
        }
        // Check Columns
        for(int i = 0; i < 3; i++){
            if(matrix[0][i] != '-' && matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]){
                cout << "Player " << (matrix[i][0] == player1Symbol ? 1 : 2) << " Won!" << endl;
                return true;
            }
        }

        // Check diagonals
        if (matrix[0][0] != '-' && matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
            cout << "Player " << (matrix[0][0] == player1Symbol ? 1 : 2) << " Won!" << endl;
            return true;
        }
        if (matrix[0][2] != '-' && matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
            cout << "Player " << (matrix[0][2] == player1Symbol ? 1 : 2) << " Won!" << endl;
            return true;
        }
        return false;
    }
    void drawMatrix(){
        cout << "-------------------" << endl;
        cout << "|  " << matrix[0][0] << "  |  " << matrix[0][1] << "  |  " << matrix[0][2] << "  |" << endl;
        cout << "-------------------" << endl;
        cout << "|  " << matrix[1][0] << "  |  " << matrix[1][1] << "  |  " << matrix[1][2] << "  |" << endl;
        cout << "-------------------" << endl;
        cout << "|  " << matrix[2][0] << "  |  " << matrix[2][1] << "  |  " << matrix[2][2] << "  |" << endl;
        cout << "-------------------" << endl;
        if(!check()){
            input();
        }
        return;
    }
    void input(){
        int row, col;
        char playerSymbol = (player1Turn) ? player1Symbol : player2Symbol;

        while (true) {
            cout << "Player " << (player1Turn ? "1" : "2") << " Turn: Enter " << playerSymbol << " place of input (row, col): ";
            cin >> row >> col;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && matrix[row][col] == '-') {
                matrix[row][col] = playerSymbol;
                break; // Exit the loop if input is valid
            } else {
                // Display error message if the position is out of bounds or already occupied
                cout << "Invalid input! Please enter row and column again." << endl;
            }
        }

        // Update player's turn
        player1Turn = !player1Turn;

        // Display the updated game board
        drawMatrix();
    }
public:
    void startGame(){
        while(true){    
            cout << "Player 1, Choose 0 or X: ";
            cin >> player1Symbol;
            if(player1Symbol == '0'){
                player2Symbol = 'X';
                cout << "Player 2, X is ur symbol. Go Ahead!" << endl << endl;
                break;
            }
            else if(player1Symbol ==  'X'){
                player2Symbol = '0';
                cout << "Player 2, 0 is ur symbol. Go Ahead!" << endl << endl;
                break;
            }
            else{
                cout << endl
                    << "Invalid Input! Choose again." << endl;
            }
        }
        input();
    }
};

int main(){
    TickTacToe game;
    game.startGame();
    return 0;
}