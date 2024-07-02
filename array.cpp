#include <iostream>

using namespace std;

template <typename T>
T sum(T array[], int size){
    T result = 0;
    for (int i = 0; i < size; i++){
        result += array[i];
    }
    return result;
}
int main(){
    cout << "template for sum()" << endl;
    int a[] = {1, 2, 3};
    double b[] = {2.1, 3.4, 5.5};
    cout << sum(a, 3) << endl;
    cout << sum(b, 3) << endl;
}