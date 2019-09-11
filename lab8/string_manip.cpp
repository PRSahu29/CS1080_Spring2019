// Please place your information here
//Piyush Ranjan Sahu, M12871655

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

// This prototype is complete
class stringManip {
public:
    stringManip();
    stringManip(string input);
    string retrieve();
    void setString(string input);
    void chop();
    void padString(int n);
    void center(int length);
    void truncate(int n);
    void removeNonAlpha();
    void convertToUpperCase();
    void convertToLowerCase();
private:
    string tobeEdited;
};

// Not all functions are defined here

// Default Constructor
stringManip::stringManip(){
    // finish me
    tobeEdited = "";
}

// Overloaded Constructor
stringManip::stringManip(string in_string){
    // finish me
    tobeEdited = in_string;
}

// retrieve function
string stringManip::retrieve(){
    // finish me
    return tobeEdited;
}

// padString() function
void stringManip::padString(int length){
    // finish me
    while(tobeEdited.length()<length)
        tobeEdited+=' ';
}

// setString() function
void stringManip::setString(string input) {
    tobeEdited = input;
}

// Add rest of functions here

//Help taken from Manvith
void stringManip::chop(){
    if (tobeEdited != ""){
        string str = "";
        int startIndex;
        int endIndex;
        for (int i = 0; i < tobeEdited.size(); ++i) {
            if (isspace(tobeEdited.at(i)) == false){
                startIndex = i;
                break;
            }
        }
        
        for (int i = tobeEdited.size()-1; i >= 0 ; --i) {
            if (isspace(tobeEdited.at(i)) == false){
                endIndex = i;
                break;
            }
        }
        
        for (int i = startIndex;i < endIndex+1; ++i) {
            str += tobeEdited.at(i);
        }
        tobeEdited = str;
    }
}

/* Didn't work because it removed the character in front of the required character:
void stringManip::chop() {
    int i=1;
    while(i<tobeEdited.length()) {
        if(tobeEdited.at(i)==' ')
            tobeEdited.erase(i,1);
        i++;
    }
    cout<<tobeEdited.length();
}
 */


void stringManip::center(int length) {
    chop();
    int ext, space, i, x;
    string temp = tobeEdited;
    ext = length - temp.length();
    if(ext < 0)
        cout<<"String is bigger than passed string length.";
    
    else if(ext > 0) {
        if(ext%2 == 0) {
            i = 0;
            space = ext/2;
            while (i < space){
                temp.insert(i, " ");
                ++i;
            }
            temp.resize(length);
            
            i = temp.size()-1;
            x=0;
            while(x < space){
                temp.at(i) = ' ';
                i--;
                x++;
            }
        }
        
        else if(ext%2 == 1) {
            i = 0;
            space = ext/2;
            while (i < space){
                temp.insert(i, " ");
                ++i;
            }
            temp.resize(length);
            
            i = temp.size()-1;
            x=0;
            while(x < space+1){
                temp.at(i) = ' ';
                i--;
                x++;
            }
        }
    }
    tobeEdited = temp;
}

void stringManip::truncate(int n) {
    if(tobeEdited.size()>n)
    tobeEdited.resize(n);
}

void stringManip::removeNonAlpha() {
    int i=0;
    while(i<tobeEdited.length()) {
        if(isalpha(tobeEdited.at(i))==0) {
            tobeEdited.erase(i,1);
            i--;
        }
        i++;
    }
}

void stringManip::convertToUpperCase() {
    int i=0;
    
    while( i < tobeEdited.length()) {
        tobeEdited.at(i) = toupper(tobeEdited.at(i));
        i++;
    }
}
    
void stringManip::convertToLowerCase() {
    int i=0;
    
    while( i < tobeEdited.length()) {
        tobeEdited.at(i) = tolower(tobeEdited.at(i));
        i++;
    }
}

// Add test cases to main()
int main(){
    stringManip S1;
    stringManip S2("  testing 123");
    
    // Test case for padString() You should correct some of your own.
    cout << "S2 before padString(20): <" << S2.retrieve() << ">" << endl;
    S2.padString(20);
    cout << "S2 after padString(20): <" << S2.retrieve() << ">" << endl;
    cout << "Should be: <testing 123       >" << endl;
    S2.chop();
    cout<<"S2 after chop(): <"<<S2.retrieve()<<">"<<endl;
    S2.truncate(3);
    cout<<"S2 after truncate(): <"<<S2.retrieve()<<">"<<endl;
    
    stringManip S3("   testing 123");
    
    S3.removeNonAlpha();
    cout<<"S3 after removeNonAlpha(): <"<<S3.retrieve()<<">"<<endl;
    S3.convertToUpperCase();
    cout<<"S3 after convertToUpperCase(): <"<<S3.retrieve()<<">"<<endl;
    S3.convertToLowerCase();
    cout<<"S3 after converttoLowerCase(): <"<<S3.retrieve()<<">"<<endl;
    S3.center(20);
    cout<<"S3 after center(): <"<<S3.retrieve()<<">"<<endl;
    
    
    return 0;
}
