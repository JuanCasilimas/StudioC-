/*
Convert C to C++ Code
jcasilimas coder 
May 10, 2024 
*/

#include <iostream>
#include <vector>

const int N = 40;

using namespace std;

void sum(int& accum, const vector<int>& data){
    accum = 0;
    for(auto num : data){
        accum += num;
    }
}

int main(){
    int accum = 0; 
    vector<int> data(N);

    for(int i = 0; i < N; i++){
        data[i] = i;
    }

    sum(accum, data);
    cout << "sum is " << accum << endl;

    return 0;

}