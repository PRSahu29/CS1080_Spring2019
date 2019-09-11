
// placeholder file
// place your code here
//
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI=3.1415926545;

double Fre_To_Omega(double f) {
    double omega;
    omega = 2*PI*f;
    return omega;
}

double CurrentAmpl(double o, double R, double L, double C, double E) {
    double A,d1,d2;
    d1 = (L*pow(o,2))-(1/C);
    d2 = pow(R,2)*pow(o,2);
    A = (o*E)/(sqrt(pow(d1,2)+d2));
    return A;
}

double PhaseAngle(double o, double R, double L, double C) {
    double phi;
    phi = 57.2958*(atan((L*o/R)-(1/(R*C*o))));
    //57.2958*(atan((L*w/R)-(1/(R*C*w))));
    return phi;
}

double AV(double E, double o, double t) {
    double apv;
    apv = E*sin(o*t);
    return apv;
}

double totalCurr(double A, double o, double phi, double t) {
    double I;
    I = A*sin((o*t-0.0174533 * phi));
    return I;
}

double RV(double A, double o, double phi, double t, double R) {
    double RVD;
    RVD = R*A*sin((o*t-0.0174533 * phi));
    return RVD;
}
double IV(double A, double o, double phi, double t, double L) {
    double IVD;
    IVD = L*o*A*cos((o*t-0.0174533 * phi));
    return IVD;
}
double CV(double A, double o, double phi, double t, double C) {
    double CVD;
    CVD = (-1/(C*o))*A*cos((o*t-0.0174533 * phi));
    return CVD;
}
/*
double VT(double RVD, double IVD, double CVD) {
    double VoltT;
    VoltT = RVD+IVD+CVD;
    return VoltT;
}
*/
int main() {
    double E,f,R,L,C,nstep;
    double omega, curAmp, phase;
    double i=0;
    
    //all inputs
    cout<<"Enter Applied Voltage amplitude (V): ";
    cin>>E;
    cout<<"Enter line frequency (Hz): ";
    cin>>f;
    cout<<"Enter Resistor value (ohms): ";
    cin>>R;
    cout<<"Enter Inductor value (Henrys): ";
    cin>>L;
    cout<<"Enter Capacitance value (F): ";
    cin>>C;
    cout<<"How many pts/AC Period? : ";
    cin>>nstep;
    
    //function calls
    omega = Fre_To_Omega(f);
    curAmp = CurrentAmpl(omega, R, L, C, E);
    phase = PhaseAngle(omega, R, L, C);
    double Vtotal;
    
    //display
    cout<<"Iter.\tTime\t\tAV\t\tI\t\tVR\t\tVL\t\tVC\t\tVT\tVdiff"<<endl;
    
    int count=0;
    for(i=0;i<0.04;i+=(0.02/nstep)) {
        count++;
        Vtotal = RV(curAmp, omega, phase, i, R) + IV(curAmp, omega, phase, i, L) + CV(curAmp, omega, phase, i, C);
        cout<<fixed<<setw(5)<<setprecision(3)<<count<<"\t"
        <<i<<"\t"
        <<fixed<<setw(7)<<right<<setprecision(3)<<AV(E, omega, i)<<"\t"
        <<fixed<<setw(7)<<right<<setprecision(3)<<totalCurr(curAmp, omega, phase, i)<<"\t"
        <<fixed<<setw(7)<<right<<setprecision(3)<<RV(curAmp, omega, phase, i, R)<<"\t"
        <<fixed<<setw(7)<<right<<setprecision(3)<<IV(curAmp, omega, phase, i, L)<<"\t"
        <<fixed<<setw(7)<<right<<setprecision(3)<<CV(curAmp, omega, phase, i, C)<<"\t"
        <<fixed<<setw(7)<<right<<setprecision(3)<<Vtotal
        <<fixed<<setw(7)<<right<<setprecision(3)<<Vtotal-(RV(curAmp, omega, phase, i, R) + IV(curAmp, omega, phase, i, L) + CV(curAmp, omega, phase, i, C))<<endl;
    }
    
    return 0;
}
//
// See the google docs for details

