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

class quad {
public:
    //default constructor
    quad() {
        P1.setX(0);
        P1.setY(0);
        P2.setX(0);
        P2.setY(0);
        P3.setX(0);
        P3.setY(0);
        P4.setX(0);
        P4.setY(0);
    }
    
    //parameterized constructor
    quad(int in_x1, int in_y1, int in_x2, int in_y2, int in_x3, int in_y3, int in_x4, int in_y4){
        P1.setX(in_x1);
        P1.setY(in_y1);
        P2.setX(in_x2);
        P2.setY(in_y2);
        P3.setX(in_x3);
        P3.setY(in_y3);
        P4.setX(in_x4);
        P4.setY(in_y4);
    }
    
    bool isQuadrilateral() {
        if((P1.getX()*(P2.getY()-P3.getY()))+(P2.getX()*(P3.getY()-P1.getY()))+(P3.getX()*(P1.getY()-P2.getY()))==0)
            return false;
        else if((P2.getX()*(P3.getY()-P4.getY()))+(P3.getX()*(P4.getY()-P2.getY()))+(P4.getX()*(P2.getY()-P3.getY()))==0)
            return false;
        else if((P1.getX()*(P3.getY()-P4.getY()))+(P3.getX()*(P4.getY()-P1.getY()))+(P4.getX()*(P3.getY()-P1.getY()))==0)
            return false;
        else if((P1.getX()*(P2.getY()-P4.getY()))+(P2.getX()*(P4.getY()-P1.getY()))+(P4.getX()*(P1.getY()-P2.getY()))==0)
            return false;
        else
            return true;
    }
    
    double perimeterQuad() {
        double per;
        double l1 = pow(pow(P2.getX()-(P1.getX()),2) + pow(P2.getY()-P1.getY(),2),0.5);
        double l2 = pow(pow(P3.getX()-(P2.getX()),2) + pow(P3.getY()-P2.getY(),2),0.5);
        double l3 = pow(pow(P4.getX()-(P3.getX()),2) + pow(P4.getY()-P3.getY(),2),0.5);
        double l4 = pow(pow(P1.getX()-(P4.getX()),2) + pow(P1.getY()-P4.getY(),2),0.5);
        per = l1+l2+l3+l4;
        
        return per;
    }
    
    double areaQaud() {
        double area, area1, area2, per1, per2;
        double l1 = pow(pow(P2.getX()-(P1.getX()),2) + pow(P2.getY()-P1.getY(),2),0.5);
        double l2 = pow(pow(P3.getX()-(P2.getX()),2) + pow(P3.getY()-P2.getY(),2),0.5);
        double l3 = pow(pow(P4.getX()-(P3.getX()),2) + pow(P4.getY()-P3.getY(),2),0.5);
        double l4 = pow(pow(P1.getX()-(P4.getX()),2) + pow(P1.getY()-P4.getY(),2),0.5);
        
        per1 = (l1+l2+l4)/2;
        area1 = sqrt(per1*(per1-l1)*(per1-l2)*(per1-l4));
        
        per2 = (l2+l3+l4)/2;
        area2 = sqrt(per2*(per2-l2)*(per2-l3)*(per2-l4));
        
        area = area1 + area2;
        
        return area;
    }
    
    bool operator== (quad &rhs) {
        if((P1.getX()==rhs.P1.getX())&&(P1.getY()==rhs.P1.getY())&&(P2.getX()==rhs.P2.getX())&&(P2.getY()==rhs.P2.getY())&&(P3.getX()==rhs.P3.getX())&&(P3.getY()==rhs.P3.getY())&&(P4.getX()==rhs.P4.getX())&&(P4.getY()==rhs.P4.getY()))
            return true;
        else
            return false;
    }
    
private:
    Point P1,P2,P3,P4;
    
    friend istream & operator>>( istream &input, quad &Q ) {
        input >> Q.P1 >> Q.P2 >> Q.P3 >> Q.P4;
        return input;
    }
    
    friend ostream & operator<<( ostream &output, quad &Q ){
        output << "p1: " << Q.P1 <<endl<< "p2: " << Q.P2<<endl<< "p3: " << Q.P3<<endl<< "p4: " << Q.P4<<endl<<endl;
        return output;
    }
};

int main() {
    
    quad q1;
    quad q2(0,0,0,1,1,1,1,0);
    quad q3;
    
    cout<<"Enter 4 coordinates for the quedrilateral: "<<endl;
    cin>>q3;
    cout<<q3;
    
    if((q2.isQuadrilateral()==true)&&(q3.isQuadrilateral()==true)) {
        cout<<"Perimeter of the quadrilateral: "<<q3.perimeterQuad()<<endl;
        cout<<"Area of the quadrilateral: "<<q3.areaQaud()<<endl;
        
        if(q2==q3)
            cout<<"quadrilaterals are equal."<<endl;
        else
            cout<<"quadrilaterals are NOT equal."<<endl;
            
    }
    else
        cout<<"It is not a quadrilateral."<<endl;
    
    return 0;
}
