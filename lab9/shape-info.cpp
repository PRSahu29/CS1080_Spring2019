#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
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
        per = (l1+l2+l3);
        
        return per;
    }
    
    double areaTriangle() {
        double area, p;
        p = (perimeterTriangle()/2);
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
//        double area, area1, area2, per1, per2;
//        double l1 = pow(pow(P2.getX()-(P1.getX()),2) + pow(P2.getY()-P1.getY(),2),0.5);
//        double l2 = pow(pow(P3.getX()-(P2.getX()),2) + pow(P3.getY()-P2.getY(),2),0.5);
//        double l3 = pow(pow(P4.getX()-(P3.getX()),2) + pow(P4.getY()-P3.getY(),2),0.5);
//        double l4 = pow(pow(P1.getX()-(P4.getX()),2) + pow(P1.getY()-P4.getY(),2),0.5);
//
//        per1 = (l1+l2+l4)/2;
//        area1 = sqrt(per1*(per1-l1)*(per1-l2)*(per1-l4));
//
//        per2 = (l2+l3+l4)/2;
//        area2 = sqrt(per2*(per2-l2)*(per2-l3)*(per2-l4));
//        area = area1 + area2;
        
        double area;
        area = 0.5*((P1.getX()*P2.getY())+(P2.getX()*P3.getY())+(P3.getX()*P4.getY())+(P4.getX()*P1.getY())-(P2.getX()*P1.getY())-(P3.getX()*P2.getY())-(P4.getX()*P3.getY())-(P1.getX()*P4.getY()));
        
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

vector<double> breakupstring(string str) {
    vector<double> numdata;
    stringstream ss;
    ss<<str;
    
    while(!ss.eof()){
        double temp;
        ss>>temp;
        numdata.push_back(temp);
    }
    
    return numdata;
}

int main() {
    string line;                    //string which stores the line read from the file
    ifstream shape_file;            //file stream object
    ofstream outfile;
    vector<double> coordinates;     //vector to store the coordinates from the text file
    int i=0;                        //incrementor
    
    shape_file.open("shapes.txt",ios::in);
    outfile.open("shape-info.txt",ios::out);
    
    if(shape_file.is_open()) {
        
        while(shape_file.good()){
            
            getline(shape_file, line);
            coordinates = breakupstring(line);
            
            for(i=0;i<coordinates.size();++i)
                cout<<coordinates.at(i)<<"\t";
            cout<<endl;
            
            if(i==6){
                triangle t(coordinates.at(0),coordinates.at(1),coordinates.at(2),coordinates.at(3),coordinates.at(4),coordinates.at(5));                     //triangle class object
                outfile<<"\n\nSufficient coordinates input."<<endl;
                if(t.isTriangle()==true){
                    outfile<<"It's a triangle."<<endl;
                    if(t.isEquilateral()==true)
                        outfile<<"The triangle is equilateral."<<endl;
                    else
                        outfile<<"The triangle is NOT equilateral."<<endl;
                    outfile<<"The perimeter of the triangle is: "<<t.perimeterTriangle()<<" units"<<endl;
                    outfile<<"The area of the triangle is: "<<t.areaTriangle()<<" units"<<endl;
                }
                else
                    outfile<<"It's not a triangle."<<endl;
            }
            
            else if(i==8){
                quad q(coordinates.at(0),coordinates.at(1),coordinates.at(2),coordinates.at(3),coordinates.at(4),coordinates.at(5),coordinates.at(6),coordinates.at(7));                         //quadrilateral class object
                outfile<<"\n\nSufficient coordinates input."<<endl;
                if(q.isQuadrilateral()==true){
                    outfile<<"It's a quadrilateral."<<endl;
                    outfile<<"Perimeter of the quadrilateral: "<<q.perimeterQuad()<<" units"<<endl;
                    outfile<<"Area of the quadrilateral: "<<q.areaQaud()<<" units"<<endl;
                }
                else
                    outfile<<"It's not a quadrilateral."<<endl;
            }
            
            else if(i==4){
                circle c(coordinates.at(0),coordinates.at(1),coordinates.at(2),coordinates.at(3));                       //circle class object
                outfile<<"\n\nSufficient coordinates input."<<endl;
                if(c.isCircle()){
                    outfile<<"It's a circle."<<endl;
                    outfile<<"Radius of the circle is: "<<c.radius()<<" units"<<endl;
                    outfile<<"Diameter of the circle is: "<<c.diameter()<<" units"<<endl;
                    outfile<<"Area of the circle is: "<<c.areaCircle()<<" units"<<endl;
                    outfile<<"Circumference of the circle is: "<<c.circumCircle()<<" units"<<endl;
                }
                else
                    outfile<<"It's NOT a circle."<<endl;
            }
            else
                outfile<<"\n\nSufficient coordinates NOT input."<<endl;
        }
    }
    else
        cout<<"unable to open the text file."<<endl;
    shape_file.close();
    outfile.close();
    return 0;
}
