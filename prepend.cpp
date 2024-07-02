#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec = {2, 4, 5};

    //prepend 1 to the vector
    vec.insert(vec.begin(), 1);

    for (int i : vec){
        std::cout << i << " ";
    }

    return 0;
}