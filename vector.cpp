#include <iostream>
#include <vector>

using namespace std;

int main(){
    int how_many;
    cout << "how many ints in data" << endl;
    cin >> how_many;

    vector<int> data (how_many);
    cout << "The contents of data: ";

    for(vector<int> :: iterator it = data.begin(); it != data.end(); ++it){
        cin >> *it;
    }

    int sum = 0;
    for(int i = 0; i < how_many; ++i){
        sum += data[i];
    }

    cout << "The sum of the elements in data is: " << sum << endl;

    return 0;
}