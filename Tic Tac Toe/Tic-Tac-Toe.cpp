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
        cout << "-------------------" << endl << endl;
        return;
    }
    bool tie(){
        // Checks if all cells are filled with symbols (neither player has won) to declare a tie 
        for(int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if(matrix[i][j] == '-')
                    return false;
            }
        }
        return true;
    }
    void input(){
        // Display the updated game board
        drawMatrix();

        int row, col;
        char playerSymbol = (player1Turn) ? player1Symbol : player2Symbol;

        while (true) {
            cout << "Player " << (player1Turn ? "1" : "2") << ", Enter " << playerSymbol << " (row, col): ";
            if (!(cin >> row >> col)) { // Check if input is not of integer type
            cout << "Invalid input! Please enter row and column again." << endl;
            cin.clear(); // Clear the error state
            cin.ignore(INT32_MAX, '\n'); // Ignore invalid input
            continue;
        }

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && matrix[row][col] == '-') {
                matrix[row][col] = playerSymbol;
                break; // Exit the loop if input is valid
            } else {
                // Display error message if the position is out of bounds or already occupied
                cout << "Invalid input! Please enter row and column again." << endl;
                fflush(stdin);
            }
        }

        // Update player's turn
        player1Turn = !player1Turn;

        if(check()){
            // Print the last version of Matrix if any player wins and exits the function
            drawMatrix();
            return;
        }
        else if(tie()){
            // Checks if the Game is tie
            cout << "The Game is a Tie!" << endl;
            drawMatrix();
            return;
        }

        input();
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