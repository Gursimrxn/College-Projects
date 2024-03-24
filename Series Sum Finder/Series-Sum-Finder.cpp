#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class seriesSumFinder{
    long long n;
public:
    void findSum(){
        unsigned long long sum = 0;
        long long currentSum = 0;
        
        cout << "Enter a positive integer: " << endl << "> ";
        cin >> n;
        
        for(int i = 1; i <= n; i++){
            currentSum += i;
            sum += currentSum;
        }

        cout << "Sum of the Series till " << n << ": "  << endl << "> " << sum << endl;
    }
};

int main(){
    seriesSumFinder obj;
    obj.findSum();
    cout << "================ Program Terminated =================" << endl << endl << "Press any key...";
    getch();
    system("cls");
    return 0;
}