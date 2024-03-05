#include<iostream>
using namespace std;

class computation{
private:
public:
    int compute(int a, int b){
        return a + b;
    }
    float compute(int a, float b){
        return a + b;
    }
    double compute(int a, double b){
        return a + b;
    }
    int compute(char a, char b){
        return a + b;
    }
    char compute(char a, int b){
        return a + b;
    }
    int compute(){
        return 0;
    }
};
int main() {
    computation c;

    cout << "Integer addition: 1 + 2 :" << endl << c.compute(1, 2) << endl << endl;
    cout << "Float addition: 1 + 2.5f :" << endl << c.compute(1, 2.5f) << endl << endl;
    cout << "Double addition: 1 + 2.5 :" << endl << c.compute(1, 2.5) << endl << endl;
    cout << "Ascii value addition: 'a' + 'b' :" << endl << c.compute('a', 'b') << endl << endl;
    cout << "Char and Integer addition: 'a' + 2 :" << endl << c.compute('a', 2) << endl << endl;
    cout << "Result of no parameters: " << endl << c.compute() << endl;

    return 0;
}