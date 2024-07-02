#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;
int main(void){
    ifstream data_file("data.txt"); 
    istream_iterator<int> start(data_file), end;
    vector<int> data(start, end);

    int sum = 0;
    for(auto it = start; it != end; ++it){
        sum += *it;
    } 
    cout << "Sum = " << sum << endl;
    cout << "average = " << 1.0 * sum/data.size() << endl;
    return 0;
}