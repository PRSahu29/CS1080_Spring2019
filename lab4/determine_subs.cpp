#include <iostream>

using namespace std;

// Please place your "determine substance" function and body

string determineSubstance(double bp) {
    
    int WATER_BP=100;
    int MERC_BP=357;
    int COPPER_BP=1187;
    int SILVER_BP=2193;
    int GOLD_BP=2660;
    
    if(bp >= (WATER_BP*.95) && bp <= (WATER_BP*1.05))
        return("Water");
    else if(bp >= (MERC_BP*.95) && bp <= (MERC_BP*1.05))
        return("Mercury");
    else if(bp >= (COPPER_BP*.95) && bp <= (COPPER_BP*1.05))
        return("Copper");
    else if(bp >= (SILVER_BP*.95) && bp <= (SILVER_BP*1.05))
        return("Silver");
    else if(bp >= (GOLD_BP*.95) && bp <= (GOLD_BP*1.05))
        return("Gold");
    else
        return("Unknown");
    return 0;
}
// See google docs for details

int main() {  //NO NEED TO CHANGE THIS
    double bp = 100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Water" << endl;
    bp = 350;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Mecury" << endl;
    bp = 2100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Silver" << endl;
    bp = 1100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Unknown" << endl;
    bp = 1150;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Copper" << endl;
    bp = 2600;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Gold" << endl;
    bp = 11000;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Known" << endl;
    return 0;
}
