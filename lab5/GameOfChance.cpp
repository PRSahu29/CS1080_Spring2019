#include <iostream>
#include <ctime>
using namespace std;
float win = 0;

int rollDie() {                     //function to generate a random number (1-6)
    int rd=rand()%6+1;
    return rd;
}

int winCounter(int win){            //function counts the number of games won
    return win;
}

bool playOneGame(int pt) {          //function compiles one instance of a game
    int Record[3],temp,count=0;
    bool var = false;
    for(int i=0;i<3;i++){
        temp = rollDie();
        cout<<"Roll #"<<i+1<<" is "<<temp<<endl;
        Record[i] = temp;
    }
    for(int i=0;i<3;i++){
        if(Record[i]==pt){
            var = true;
            count = winCounter(true);
            break;
        }
        else
            var = false;
    }
    return var;
}

int Wager(int w, bool isWon, int bal) {     //function adds/subtracts money according to
    if(isWon==true)                         //game won or lost
        bal += w;
    else if(isWon==false)
        bal -= w;
    return bal;
}

int UsrInput(int acb) {                     //function takes in user input
    int w;
    cout<<"Account Balance: $"<<acb<<endl;
    do{
        cout<<"Enter Wager (0 to exit): ";
        cin>>w;
    }while(w<0 || w>acb);
    return w;
}

int Execute(int wage, int nb ) {            //function executes the result (won or lost)
    int point;
    bool isWon;
    do{
        cout<<"\nChoose your point (1-6): ";
        cin>>point;
    }while(point<1 || point > 6);
    isWon = playOneGame(point);
    if(isWon==true) {
        cout<<" ** You win ** "<<endl;
        win+=1;
        return Wager(wage, isWon, nb);
        //return bal;
    }
    else {
        cout<<" ** You Lose ** "<<endl;
        return Wager(wage, isWon, nb);
    }
}

int main() {
    srand(time(NULL));
    int usrInp, nb=100;
    int count=0;
    while(1){
        usrInp = UsrInput(nb);
        count++;
        if(usrInp==0) {                         //condition checking if user wants to quit the game
            if(count==0)
                cout<<"Your final account balance is: $"<<nb<<endl;
            else {
                cout<<"Your final account balance is: $"<<nb<<endl
                <<"You won "<<win<<" times out of "<<count<<" for a winning percentage of "<<(win/count)*100<<"%"<<endl;
            }
            break;
        }
        else if(usrInp>0){                      //condition either assigns the value to new balance
            nb = Execute(usrInp,nb);
            if(nb<=0) {                         //or displays the summary if the game is lost
                cout<<"Game over, you are out of money!\n"
                <<"Your final account balance is: $"<<nb<<endl
                <<"You won "<<win<<" times out of "<<count<<" for a winning percentage of "<<((win/(count))*100)<<"%"<<endl;
                break;
            }
        }
        else if(usrInp<0){                      //condition returning the cursor to the beginning if user enters
            cout<<"Invalid input"<<endl;        //an invalid entry
        }
    }
    
    return 0;
}
