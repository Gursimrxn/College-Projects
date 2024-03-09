#include <iostream>
using namespace std;

class sample {
public:
    // Function to compute the result of a member function
    int Compute(int (sample::*func)(int), int val) {
        return (this->*func)(val);
    }

    // Function to find factorial
    int findFactorial(int n){
        if(n==0)
            return 1;
        else
            return n*findFactorial(n-1);
    }

    // Function to find square
    int findSquare(int n) {
        return n * n;
    }

    // Function to find cube
    int findCube(int n) {
        return n * n * n;
    }
};

int main(int argc, char* argv[]) {
    // Check if argument is provided
    // if not, it will quit the program
    if (argc < 2) {
        cout << "Please enter an argument value through Command Line!" << endl;
        cout << "Syntax: \"./Pointer-to-functions <argument>\"" << endl;
        return 1;
    }

    // Create an object of sample class
    sample obj;

    // Assign member function pointers
    auto factorial = &sample::findFactorial;
    int (sample::*square)(int) = &sample::findSquare;
    int (sample::*cube)(int) = &sample::findCube;

    // Convert argument to integer
    int value = atoi(argv[1]);

    // Compute and print results
    cout << "Factorial of " << value << ": " << obj.Compute(factorial, value) << endl;
    cout << "Square of " << value << ": " << obj.Compute(square, value) << endl;
    cout << "Cube of " << value << ": " << obj.Compute(cube, value) << endl;

    return 0;
}
