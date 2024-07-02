#include <iostream>

using namespace std;

struct Vertice2d {
    float x, y;
    Vertice2d(float x = 0, float y = 0) : x(x), y(y) {}
};

//sobrecarga para imprimrlo completo
ostream& operator<< (ostream& os, const Vertice2d& v){
    os << "(" << "X:" << v.x << " , " << "Y:" << v.y << ")";
    return os;
}

int main(){
    Vertice2d v1(1.0, 2.0); //
    Vertice2d v2(4.0, 5.0);

    cout << "vertice 1: " << v1.x << endl;
    cout << "Vertice 2: " << v2.y << endl;
    cout << "vertice 1 complete: " << v1 << endl;

    return 0; 
}