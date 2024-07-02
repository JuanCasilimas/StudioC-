#include <iostream>

using namespace std;

class point{
    public:
    float x, y;

    point(float x = 0, float y = 0) : x(x), y(y) {}


    friend ostream& operator<<(ostream& os, const point& p){
        os << "(" << p.x << ", " << p.y << ")";
        return os; 
    }

    void move (float dx, float dy){
        x += dx;
        y += dy;
    }
};

class point3d : public point{
    public:
        float z;

        point3d(float x = 0, float y = 0, float z = 0) : point(x, y), z(z) {}

        friend ostream& operator<<(ostream& os, const point3d& p){
            os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
            return os;
        }
    void move(float dx, float dy, float dz){
        point::move(dx, dy);
        z += dz;
    }
};

int main(){
    point p1(1.0, 2.0);
    point3d p2(4.0, 3.5, 5.6);

    cout << p1 << endl;
    cout << p2 << endl;

    p1.move(1.0, 1.0);
    p2.move(1.0, 1.0, 1.0);

    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}