#include<iostream>
using namespace std;

class Number{
    int val;
public:
    Number(int n) : val(n) {}
    Number friend operator+(Number const &num1, Number const &num2){
        int sum = num1.val + num2.val;
        return Number(sum);
    } 
    Number friend operator-(Number const &num1, Number const &num2){
        int sum = num1.val - num2.val;
        return Number(sum);
    }
    void display(){
        cout << val << endl;
    }
};

int main(){
    Number num1(5);
    Number num2(10);
    Number result(0);

    result = num1 + num2 + num1 + 5;
    cout << "Addition: ";
    result.display();

    result = num1 - num2 + num1 - 5 + 1 - 23;
    cout << "Subtraction and Addition: ";
    result.display();
    

    return 0;
}