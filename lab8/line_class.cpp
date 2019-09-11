// Add your information here
//Piyush Ranjan Sahu, M12871655

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

// Please replace this Point class with your version from Part B
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

class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }
    
    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }
    
    double slope, length;
public:
    // Add your functions/methods here //
    Line() {
        P1.setX(0);
        P1.setY(0);
        P2.setX(0);
        P2.setY(0);
    }

    double getSlope() {
        return (P2.getY()-P1.getY())/(P2.getX()-P1.getX());
    }
    
    double getLength() {
        return pow(pow(P2.getX()-(P1.getX()),2) + pow(P2.getY()-P1.getY(),2),0.5);
    }
    
    int isHorizontal() {
        if(getSlope()==0)
            return 1;
        else if(getSlope()==INFINITY)
            return 2;
        else
            return 3;
    }
    
    double yIntercept() {
        return (P2.getY()-P1.getY())/(P2.getX()-P1.getX())*(-1*P2.getX());
    }
    
private:
    Point P1, P2;
};

int main(){
    Line L1;
    //Line L2(5,6,7,8);
    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl<<endl;
    
    Line L2;
    cout << "Enter Two Points For Line1: ";
    cin >> L2;
    cout << L2 << endl<<endl;
    
    Line L3;
    cout<<"Enter two points for line2: ";
    cin >> L3;
    cout << L3 << endl;
    
    cout<<"\nLine1: ";
    cout<<"Slope is: "<<L2.getSlope()<<endl
    <<"Length is: "<<L2.getLength()<<endl
    <<"Y intercept is: "<<L2.yIntercept()<<endl;
    
    if(L2.isHorizontal()==1)
        cout<<"Line is horizontal."<<endl;
    else if(L2.isHorizontal()==2)
        cout<<"Line is vertical."<<endl;
    else if((L2.isHorizontal()!=1)&&(L2.isHorizontal()!=2))
        cout<<"line is neither horizontal nor vertical."<<endl;
    
    cout<<"\nLine2: ";
    cout<<"Slope is: "<<L3.getSlope()<<endl
    <<"Length is: "<<L3.getLength()<<endl
    <<"Y intercept is: "<<L3.yIntercept()<<endl;
    
    if(L3.isHorizontal()==1)
        cout<<"Line is horizontal."<<endl;
    else if(L3.isHorizontal()==2)
        cout<<"Line is vertical."<<endl;
    else if((L2.isHorizontal()!=1)&&(L2.isHorizontal()!=2))
        cout<<"line is neither horizontal nor vertical."<<endl;
    
    if(L2.getSlope()==L3.getSlope())
        cout<<"\nLines are parallel."<<endl;
    else
        cout<<"\nLines are not parallel."<<endl;
    
    return 0;
}
