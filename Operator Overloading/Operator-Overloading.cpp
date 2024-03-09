#include<iostream>
using namespace std;

class User {
private:
    string name;
    int birth_day;
    int birth_month;
    int birth_year;
    double salary;
public:
    User(string name, int day, int month, int year, double sal){
        this->name = name;
        birth_day = day;
        birth_month = month;
        birth_year = year;
        salary = sal;
    }
    void displayDetails() {
        cout << endl << "User Details:" << endl << endl;
        cout << "Name: " << name << endl;
        cout << "Birth Date: " << birth_day << "/" << birth_month << "/" << birth_year << endl;
        cout << "Salary: $" << salary << endl;
    }
    double getSal(){
        return salary;
    }
    int operator==(User const &obj) {
        if (this->birth_year != obj.birth_year)
            return (this->birth_year > obj.birth_year) ? 1 : -1;
        if (this->birth_month != obj.birth_month)
            return (this->birth_month > obj.birth_month) ? 1 : -1;
        if (this->birth_day != obj.birth_day)
            return (this->birth_day > obj.birth_day) ? 1 : -1;
        return 0;
    }
    double operator+ (User const &obj){
        return (this->salary + obj.salary) / 2.0;
    }
    friend void operator+(int num, User &obj);
};

void operator+(int num, User &obj){
    double sal = obj.salary;
    double inc = sal * num / 100;
    obj.salary += inc;
}

int main(){
    // Create User objects
    User obj1("Raj", 20, 1, 1990, 5000);
    User obj2("Mohan", 20, 1, 1990, 1347);

    // Compare user ages
    int res = obj1 == obj2;
    cout << endl << "Comparison Result: ";
    if (res > 0)
        cout << "Raj is elder than Mohan" << endl;
    else if (res == 0)
        cout << "Both users are of the same age" << endl;
    else
        cout << "Raj is younger than Mohan" << endl;

    // Compute average salary
    double avgSal = obj1 + obj2;
    cout << endl << "Average Salary: $" << avgSal << endl << endl;

    // Display salary before and after incrementation
    cout << "Salary before incrementation: $" << obj1.getSal() << endl;
    5 + obj1; // Add 5% increment
    cout << "Salary after incrementation: $" << obj1.getSal() << endl;

    // Display user details
    obj1.displayDetails();
    obj2.displayDetails();

    return 0;
}
