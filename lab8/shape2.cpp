#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159
class Sphere {
public:
    Sphere() {
        setR(0);
    }
    Sphere(double in_R) {
        setR(in_R);
    }
    void setR(double in_R) {
        r = in_R;
    }
    
    double getR() {
        return r;
    }
    
    void display() {
        cout<<"Sphere Parameters: "<<endl;
        cout<<"Radius: "<<getR()<<endl;
        cout<<"Surface Area: "<<getSurfaceArea()<<endl;
        cout<<"Volume: "<<getVolume()<<endl;
    }
    
private:
    double r;
    
    double getSurfaceArea() {
        return 4*PI*pow(r,2);
    }
    
    double getVolume() {
        return 4*PI*pow(r,3)/3;
    }
};

int main() {
    Sphere s1;
    s1.display();
    s1.setR(4.717);
    s1.display();
    Sphere s2(6);
    s2.display();
    return 0;
}
