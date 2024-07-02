#include <iostream>
#include <cstdint>

using namespace std;

enum class days:std::int8_t{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

ostream& operator<<(ostream& out, const days& d){
    out << static_cast<int>(d); return out;
    return out;
}

days operator++(days& d){
    d = static_cast<days>((static_cast<int>(d) + 1) % 7);
    return d;
}

days operator++(days& d, int){
    days temp = d;
    d = static_cast<days>((static_cast<int>(d) + 1) % 7); //we increment d to 1 and convert to an integer
    
    return temp;
}

int main(){
    days today{days::Monday};
    cout << "Demonstrate class enum" << endl;
    cout << "Monday value is " << today << endl;
    cout << "Increment value is " << ++today << endl;
    cout << "Increment value is " << today++ << endl;
    cout << "Increment value is " << today << endl;
    
    return 0;
 }