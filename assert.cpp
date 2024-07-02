#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

//mysort defined as a function
void mysort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    std::sort(begin, end); //sort between begin and end 
}

void printvector(const std::vector<int> &v){
    for(const auto &e : v){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> d = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    mysort(d.begin(), d.end());

    assert(std::is_sorted(d.begin(), d.end()));

    printvector(d);

}