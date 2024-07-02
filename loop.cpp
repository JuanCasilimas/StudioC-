#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string a_tempo, b_tempo;

    getline(cin, a_tempo);
    getline(cin, b_tempo);

    int a = stoi(a_tempo);
    int b = stoi(b_tempo);

    const string num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight"};

    for(int i = a; i <= b; i++){
        if(i >= 1 && i <= 9){
            cout << num[i - 1] << endl;
        } else if(i > 9){
            if(i % 2 == 0){
                cout << "even" << endl;
            } else{
                cout << "odd" << endl;
            }
        }
    }

    return 0;
}



/*
#include <iostream>
#include <string>

using namespace std;

int main(){
    string a_temporal, b_temporal;
    
    getline(cin, a_temporal);
    getline(cin, b_temporal);

    int a = stoi(a_temporal);
    int b = stoi (b_temporal);

    const string num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for(int i = a; i <= b; i++){
        if(i >= 1 && i <= 9){
            cout << num[i - 1] << endl;
        } else if (i > 9){
            if ( i % 2 == 0) {
                cout << "even" << endl;
            } else {
                cout << "odd" << endl;
            }
        }
    }
     
    return 0;
} */