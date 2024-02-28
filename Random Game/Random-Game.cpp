#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class GuessTheNumber {
    int computerGeneratedNumber;
    int userGuessedNumber;
public:
    void generateRandomNumber(void);
    void startGame(void);

};
void GuessTheNumber::generateRandomNumber(){
    srand(time(nullptr));
    computerGeneratedNumber = rand() % 100 + 1;

}
void GuessTheNumber::startGame(){
    generateRandomNumber();
    for (int i = 0; computerGeneratedNumber != userGuessedNumber; i++){
        cout << "Guess the Number: ";
        cin >> userGuessedNumber;
        cout << "Attempt: " << i + 1 << endl;
        if(userGuessedNumber == computerGeneratedNumber)
            cout << "Message: Congratulation you won the game in " << i + 1 << " attempts";
        if(userGuessedNumber < computerGeneratedNumber)
            cout << "Message: Guessed number is smaller than computer generated number" << endl
                 << endl;
        else if(userGuessedNumber > computerGeneratedNumber)
            cout << "Message: Guessed number is greater than computer generated number" << endl
                 << endl;
    }
}
int main(){
    GuessTheNumber obj;
    obj.startGame();
    return 0;
}