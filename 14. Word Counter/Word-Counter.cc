#include<iostream>
#include<string>
using namespace std;

class WordCounter{
    string str;
public:
    WordCounter(string s){
        str = s;
    }
    int countWords(){
        int count = 0;
        for(int i = 1; i < str.length(); i++){
            if(str[i] == ' ' and str[i - 1] != ' ')
                count++;
        }
        return count;
    }
};
int main(){
    WordCounter wc("   hello world, My name is    Gursimran    Singh    ");
    cout << "There are " << wc.countWords() << " Words in the string.";
    return 0;
}