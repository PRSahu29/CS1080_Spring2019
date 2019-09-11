#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159

class Cone {
public:
    Cone(){
        setR(0);
        setH(0);
    }
    Cone(double in_R, double in_H) {
        setR(in_R);
        setH(in_H);
    }
    
    double getR() {
        return r;
    }
    
    double getH() {
        return h;
    }
    
    void setR(double in_R) {
        r = in_R;
    }
    
    void setH(double in_H) {
        h = in_H;
    }
    
    void display() {
        cout<<"Cone parameters: "<<endl;
        cout<<"Radius: "<<getR()<<endl;
        cout<<"Height: "<<getH()<<endl;
        cout<<"Surface Area: "<<getSurfaceArea()<<endl;
        cout<<"Volume: "<<getVolume()<<endl;
    }
    
private:
    double s,r,h;
    
    double getSurfaceArea() {
        return (PI*pow(r,2)) + (PI*r*pow(((r*r)+(h*h)),0.5));
    }
    
    double getVolume() {
        return (PI*r*r*h)/3;
    }
};

int main() {
    Cone c1;
    c1.display();
    c1.setH(4.56);
    c1.setR(2.8);
    c1.display();
    Cone c2(7,9);
    c2.display();
    return 0;
}
