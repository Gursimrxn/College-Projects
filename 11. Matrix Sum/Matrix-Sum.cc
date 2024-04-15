#include<iostream>
using namespace std;

class Matrix{
    int m[3][3];
public:
    void setValues(){
        cout << "Enter Values: ";
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                cin >> m[i][j];
    }
    void display(){
        cout << "Matrix Values: " << endl;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& obj){
        Matrix obj3;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                obj3.m[i][j] = this->m[i][j] + obj.m[i][j];
            }
        }
        return obj3;
    }
};

int main(){
    Matrix obj1, obj2;
    obj1.setValues();
    obj2.setValues();

    Matrix obj3 = obj1 + obj2;

    obj3.display();

    return 0;
}