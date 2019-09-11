// placeholder file
// place your code here

#include <iostream>
#include <cmath>
const double TOLERANCE = 0.001;
using namespace std;

double newtonRoot(double);      //call to find the root of the equation
double f(double);               //function
double fprime(double);          //function's derivative

int main() {
    int guess;
    double root;
    char opt;
    do{
        cout<<"Enter Guess: ";
        cin>>guess;
        root = newtonRoot(guess);
        cout<<"Root: "<<root;
        cout<<"\nEnter Another Guess: y/n? ";
        cin>>opt;
    }while(opt!='n');
    //cout<<"Root: "<<root<<endl;
    return 0;
}

double newtonRoot(double a) {
    double x1;
    x1 = a - (f(a)/fprime(a));
    
    while(fabs(x1-a) > TOLERANCE) {
        a = x1;
        x1 = a - (f(a)/fprime(a));
        //cout<<x1;
    }
    return x1;
}

double f(double a) {
    return pow(a,4)+(2*pow(a,3))-(31*pow(a,2))-(32*a)+60;
    //return 0;
}

double fprime(double a) {
    return (4*pow(a,3))+(6*pow(a,2))-(62*a)-32;
}


//
//
// See the google docs for details

