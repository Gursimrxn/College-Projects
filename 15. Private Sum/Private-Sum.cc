#include<iostream>
using namespace std;
class Float;
class Integer{
    int val;
public: 
    Integer(int value) : val(value) {}
    friend float operator+(Integer &, Float &);
};

class Float{
    float val;
public: 
    Float(float value) : val(value) {}
    friend float operator+(Integer &, Float &);

};
float operator+(Integer& I, Float& F){
    return I.val + F.val;
}
int main(){
    Integer IntegerObj(12);
    Float FloatObj(35.12f);

    double result = IntegerObj + FloatObj;

    cout << "The sum is: " << result << endl;

    return 0;
}