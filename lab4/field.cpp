// placeholder file
// place your code here
//
#include <iostream>
#include <cmath>
using namespace std;

double Efield(double r, double a=1); //a = 1 needs to remain!

int main() {
    double fld,rad,a1;
    cout<<"Enter r: ";
    cin>>rad;
    cout<<"Enter a: ";
    cin>>a1;
    fld=Efield(rad,a1);
    cout<<"Efield: "<<fld<<endl;
    return 0;
}

double Efield(double r, double a) {
    double Ke = 9*pow(10,9);
    double Q = pow(10,-9);
    double field = 0;
    if(r<a)
        field = (Q*Ke*r)/pow(a,3);
    else if (r>=a)
        field = Ke*Q/pow(r,2);
    return field;
    
}
//
// See the google docs for details
