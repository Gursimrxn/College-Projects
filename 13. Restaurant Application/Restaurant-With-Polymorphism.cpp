#include<iostream>
using namespace std;

class Restaurant{
public:
    virtual void order() = 0;
    virtual void price() = 0;
};

class Samosa : public Restaurant{
public:
    void order(){
        cout << "Ordering Samosa" << endl;
    }
    void price(){
        cout << "Price of Samosa is 100" << endl;
    }
};

class Pizza : public Restaurant{
public:
    void order(){
        cout << "Ordering Pizza" << endl;
    }
    void price(){
        cout << "Price of Pizza is 200" << endl;
    }
};

class Burger : public Restaurant{
public:
    void order(){
        cout << "Ordering Burger" << endl;
    }
    void price(){
        cout << "Price of Burger is 300" << endl;
    }
};

class Noodles : public Restaurant{
public:
    void order(){
        cout << "Ordering Noodles" << endl;
    }
    void price(){
        cout << "Price of Noodles is 400" << endl;
    }
};

class Customer{
    Restaurant *r;
public:
    Customer(Restaurant* request) {
        r = request;
    }
    void order(){
        r->order();
        r->price();
    }
};

int main(){
    Restaurant* request = new Samosa();
    Customer c1(request);
    c1.order(); // This will order samosa
    c1.order(); // This will order samosa
    
    // request = new Noodles();
    // Customer c2(request);
    // c2.order(); // This will order noodles

    return 0;
}