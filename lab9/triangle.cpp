#include <iostream>
#include <cmath>
using namespace std;

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

class triangle {
public:
    //default constructor
    triangle() {
        P1.setX(0);
        P1.setY(0);
        P2.setX(0);
        P2.setY(0);
        P3.setX(0);
        P3.setY(0);
    }
    
    //parameterized constructor
    triangle(int in_x1, int in_y1, int in_x2, int in_y2, int in_x3, int in_y3){
        P1.setX(in_x1);
        P1.setY(in_y1);
        P2.setX(in_x2);
        P2.setY(in_y2);
        P3.setX(in_x3);
        P3.setY(in_y3);
    }
    
    bool isTriangle() {
        bool tri = true;
        double sl1, sl2;
        sl1 = (P2.getY()-P1.getY())/(P2.getX()-P1.getX());
        sl2 = (P3.getY()-P2.getY())/(P3.getX()-P2.getX());
        
        if(sl1 == sl2)
            tri = false;
        else if (sl1 != sl2)
            tri = true;
        
        return tri;
    }
    
    double perimeterTriangle() {
        double per;
        double l1 = pow(pow(P2.getX()-(P1.getX()),2) + pow(P2.getY()-P1.getY(),2),0.5);
        double l2 = pow(pow(P3.getX()-(P2.getX()),2) + pow(P3.getY()-P2.getY(),2),0.5);
        double l3 = pow(pow(P1.getX()-(P3.getX()),2) + pow(P1.getY()-P3.getY(),2),0.5);;
        per = (l1+l2+l3)/2;
        
        return per;
    }
    
    double areaTriangle() {
        double area, p;
        p = perimeterTriangle();
        double l1 = pow(pow(P2.getX()-(P1.getX()),2) + pow(P2.getY()-P1.getY(),2),0.5);
        double l2 = pow(pow(P3.getX()-(P2.getX()),2) + pow(P3.getY()-P2.getY(),2),0.5);
        double l3 = pow(pow(P1.getX()-(P3.getX()),2) + pow(P1.getY()-P3.getY(),2),0.5);;
        area = sqrt(p*(p-l1)*(p-l2)*(p-l3));
        return area;
    }
    
    bool isEquilateral() {
        double l1 = pow(pow(P2.getX()-(P1.getX()),2) + pow(P2.getY()-P1.getY(),2),0.5);
        double l2 = pow(pow(P3.getX()-(P2.getX()),2) + pow(P3.getY()-P2.getY(),2),0.5);
        double l3 = pow(pow(P1.getX()-(P3.getX()),2) + pow(P1.getY()-P3.getY(),2),0.5);;
        bool iseq = false;
        if(l1==l2==l3)
            iseq = true;
        else
            iseq = false;
        
        return iseq;
    }
    
    bool operator== (triangle &rhs){
        if((P1.getX()==rhs.P1.getX())&&(P2.getX()==rhs.P2.getX())&&(P3.getX()==rhs.P3.getX())&&(P1.getY()==rhs.P1.getY())&&(P2.getY()==rhs.P2.getY())&&(P3.getY()==rhs.P3.getY()))
            return true;
        else
            return false;
    }
    
private:
    Point P1,P2,P3;
    
    friend istream & operator>>( istream &input, triangle &T ) {
        input >> T.P1 >> T.P2 >> T.P3;
        return input;
    }
    
    friend ostream & operator<<( ostream &output, triangle &T ){
        output << "p1: " << T.P1 <<endl<< "p2: " << T.P2<<endl<< "p3: " << T.P3<<endl<<endl;
        return output;
    }
};

int main() {
    
    bool eq;
    triangle t1;
    triangle t2 (1,1,2,0,0,0);
    triangle t3;
    cout<<"Enter 3 coordinates for the triangle: "<<endl;
    cin>>t3;
    cout<<t3;
    
    if((t2.isTriangle()==true) && (t3.isTriangle()==true)) {
        eq = t3.isEquilateral();
        if(eq == true)
            cout<<"The triangle is equilateral"<<endl;
        else
            cout<<"The triangle is not equilateral"<<endl;
        
        cout<<"The perimeter of the triangle is: "<<t3.perimeterTriangle()<<endl;
        cout<<"The area of the triangle is: "<<t3.areaTriangle()<<endl;
        
        if(t3==t2)
            cout<<"Triangles are equal."<<endl;
        else
            cout<<"Triangles are NOT equal."<<endl;
    }
    else
        cout<<"It is not a triangle."<<endl;
    
    return 0;
}
