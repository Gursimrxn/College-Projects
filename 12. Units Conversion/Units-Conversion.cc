#include<iostream>
using namespace std;

class SmallUnit{
protected:
    double measurement;
public:
    SmallUnit(double m) : measurement(m) {}

    virtual void display(){
        cout << "Measurement in Inches: " << measurement << " inches."<< endl;
    }
};

class LargeUnit : public SmallUnit{
public:
    LargeUnit(double m) : SmallUnit(m * 12) {} // Convert to Inches
    LargeUnit(SmallUnit& obj) : SmallUnit(obj) {} // Convert to Inches 
    void display() override {
        cout << "Measurement in Feets: " << measurement / 12 << " feet." << endl; // Convert to feet
        SmallUnit::display();
    }
    
};

int main(){
    SmallUnit SmallUnitObj(48); // 48 inches 
    LargeUnit LargeUnitObj(2); // 3 feet

    SmallUnit *baseptr = &SmallUnitObj;
    cout << "Small Unit Output" << endl;
    baseptr->display();
    cout << endl;

    baseptr = &LargeUnitObj;
    cout << "Large Unit Output" << endl;
    baseptr->display();
    cout << endl;

    cout << "Large Unit with Small Unit Measurement: " << endl;
    LargeUnitObj = SmallUnitObj; // Type convertion
    LargeUnitObj.display();
    cout << endl;

    return 0;
}