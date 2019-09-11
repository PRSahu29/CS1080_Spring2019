#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

#define PI 3.14159

class Point {
    // cout implementation for Point class
    
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }
    
    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }
    
public:
    Point(){
        x = 0;
        y = 0;
    }
    
    Point(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }
    
    // Add your functions here
    void setX(double in_X){
        x = in_X;
    }
    
    void setY(double in_Y) {
        y = in_Y;
    }
    
    double getX() {
        return x;
    }
    
    double getY() {
        return y;
    }
private:
    int x,y;
};

class circle {
    Point P1,P2;
    
    friend istream & operator>>( istream &input, circle &C ) {
        input >> C.P1 >> C.P2;
        return input;
    }
        
    friend ostream & operator<<( ostream &output, circle &C ){
        output << "center: " << C.P1 <<endl<< "point on circumference: " << C.P2<<endl<<endl;
        return output;
    }

public:
    circle() {
        P1.setX(0);
        P1.setY(0);
        P2.setX(0);
        P2.setY(0);
    }
    
    circle(int in_x1, int in_y1, int in_x2, int in_y2) {
        P1.setX(in_x1);
        P1.setY(in_y1);
        P2.setX(in_x2);
        P2.setY(in_y2);
    }
    
    bool isCircle() {
        if((P1.getX()==P2.getX())&&(P1.getY()==P2.getY()))
            return false;
        else
            return true;
    }
    
    double radius() {
        return pow(pow(P2.getX()-(P1.getX()),2) + pow(P2.getY()-P1.getY(),2),0.5);
    }
    
    double diameter() {
        return 2*radius();
    }
    
    double areaCircle() {
        return pow(radius(),2)*PI;
    }
    
    double circumCircle() {
        return 2*PI*radius();
    }
    
    bool operator== (circle &rhs) {
        if((radius()==rhs.radius())&&(P1.getX()==rhs.P1.getX())&&(P1.getY()==rhs.P1.getY()))
            return true;
        else
            return false;
    }
    
};

int main() {
    circle c1;
    circle c3(2,3,5,4);
    circle c2;
    
    cout<<"Enter 2 coordinates for the center and any other point on the circle: "<<endl;
    cin>>c2;
    cout<<c2;
    
    if((c2.isCircle()==true)&&(c3.isCircle()==true)) {
        
        if(c2==c3)
            cout<<"Circles are equal."<<endl;
        else
            cout<<"Circles are NOT equal."<<endl;
        
        cout<<"Radius of the circle is: "<<c2.radius()<<endl;
        cout<<"Diameter of the circle is: "<<c2.diameter()<<endl;
        cout<<"Area of the circle is: "<<c2.areaCircle()<<endl;
        cout<<"Circumference of the circle is: "<<c2.circumCircle()<<endl;
    }
    else
        cout<<"It is not a circle.";
    return 0;
}
