// Program: exp.cpp
// Description: Test and develop a version of the exp() function - main() has test
// code to check and see if this version of exp() function works properly.

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// double factorial(int N) - returns the factorial variable N
// Please add the code necessary to calculate the factorial of the number represented by N

double factorial(int N) {
    // Insert your code here
    int ans=1;
    if(N>0)
        for(int i=N;i>0;i--)
            ans=ans*i;
    else if(N==0)
        N=1;
    double return_val = ans;
    return return_val;
}

// A clone of the system exp() function.
// Please do not use the system exp() function in the creation of your function.
double E_to_X(double X) {
    
     // Replace return statement with something more proper
    //double nno=0,pno=0;
    double value=1;
    double temp=1;
    int i;
    for(i=1;i<=30;i++) {
        temp = (temp*X)/i;
        value += temp;
    }
    /*while(count<12) {
        temp = pow(X,count)/factorial(count);
        value += temp;
        cout<<value<<"\t"<<count<<"\t";
        if(count > 2) {
            pno = nno;
            cout<<pno<<"\t"<<count<<"\t";
        ++count;
        }
        nno = temp;
        cout<<pno<<"\t"<<nno<<"\t";
        y = abs(nno-pno);
    
    value++;
    }*/
    return value;
}

// You can change main() in anyway you want
int main() {
    
    cout << fixed << "E_to_X(0) is " << E_to_X(0) << " should be 1" << endl;
    cout << fixed << "E_to_X(1) is " << E_to_X(1) << " should be 2.718" << endl;
    cout << fixed << "E_to_X(2) is " << E_to_X(2) << " should be 7.38" << endl;
    cout << fixed << "E_to_X(5) is " << E_to_X(5) << " should be 120" << endl;
    cout << fixed << "E_to_X(10) is " << E_to_X(10) << " should be 22026" << endl;
    //cout<<factorial(4);
    
    return 0;
}
