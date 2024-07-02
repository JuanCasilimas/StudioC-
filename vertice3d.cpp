#include <iostream>

using namespace std;

struct vertices3d{
    float x, y, z;
    vertices3d(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    //operator 
    vertices3d operator+ (const vertices3d other) const{
        return vertices3d(x + other.x, y + other.y, z + other.z);
    }

    vertices3d operator- (const vertices3d other) const{
        return vertices3d(x - other.x, y - other.y, z - other.z);
    }
};

ostream& operator<< (ostream& os, const vertices3d& v){
    os << "(" << "X:" << v.x << ", " << "Y:" << v.y << ", " << "Z:" << v.z << ")";
    return os;
}

int main(){
    int a = 10, b = 5;
    vertices3d v1(4.0, 3.2, 8.8);
    vertices3d v2(5.6, 7.9, 2.4);
    vertices3d v3(4.5, 6.8, 5.4);
    vertices3d v4(3.2, 2.1, 9.9);

    vertices3d sum = v1 + v2 + v3 + v4;
    vertices3d rest = v1 - v2 - v3 - v4;
    

    cout << "Vertice 1: " << v1 << "\t" << "Vertice 2:" << v2 << "\t" << "Vertice 3:" << v3 << "\t" << "Vertice 4:" << v4 << endl;
    cout << "Amount vertice: " << sum << endl;
    cout << "Rest vertice: " << rest << endl;  
    cout << a - b << endl;
    return 0;
}