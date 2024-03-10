#include<iostream>
#include<cstring>
using namespace std;

class sample{
public:
    char* name;

    sample(){}
    // Parameterized Constructor
    sample(char *str, int length){
        name = new char[length + 1];
        strcpy(name, str);
    }
    // Copy Constructor
    sample(sample const &obj){
        int len = strlen(obj.name);
        name = new char[len + 1];
        strcpy(name, obj.name);
    }
    // Destructor
    ~sample(){
        delete[] name;
    }
};

int main(){
    sample user1((char*)"chitkara", 8);
    sample user2 = user1;

    strcpy(user2.name, "dummy");

    cout << "User1 name: " << user1.name << endl << "User2 name: " << user2.name << endl;
    
    return 0;
}