/*GAME TO SAVE THE ROADSTER FROM BEING SENT INTO SPACE.
Comments explain most of the things. Other things commented out are the metrics.
 To see the location (row,column) of any object, un-comment those code blocks to see where
 the Roadster, Yugo, Pinto or Elon Musk might be spawned.
 (metric code blocks have comments next to them)
 Your location is always visible to you in the form of coordinates (row, column)
 In game instructions are included while the execution of the game.*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> Object_Spawn() {
    vector<int> objects(8);             //0,1: Roadster (r,c) 2,3: Yugo(r,c) 4,5: Pinto(r,c) 6,7: Elon(r,c)
                                        //Sorry Elon, but you're an object
    for(int i=0;i<8;i++) {
        objects[i] = rand()%15+1;       //random spawns for all objects (grid: 1 to 15 rows and columns)
    }
    return objects;
}

vector<int> PC_Spawn(vector<int> objects) {
    vector<int> character(2);            //0,1: Playable character spawn (r,c)
    int inv_spawn = 0;
    for(int j=0;j<2;j++) {
        character[j]=rand()%15+1;
        //cout<<"\n"<<character[j]<<"\n";       //original spawn metrics
    }
    
    int rows[4],cols[4],a=0,b=0;
    for(int i=0;i<8;i++) {
        if(i%2==0) {
            rows[a]=i;
            a+=1;
        }
    }
    for(int w=0;w<8;w++) {
        if(w%2==1) {
            cols[b]=w;
            b+=1;
        }
    }
    
    do{
        for(int x=0;x<4;x++) {
            //Previous, wrong method to check for invalid spawn
            //((character.at(0)>=(objects.at(x)-2))||(character.at(0)<=(objects.at(x)+2)))&&((charactesar.at(1)>=(objects.at(x)-2))||(character.at(1)<=(objects.at(x)+2)))
            //use && instead || (I'm a fool)
    
            //cout<<"\t"<<objects.at(rows[x])<<" "<<objects.at(cols[x]);        comparison metrics
            if(((character.at(0)>=(objects.at(rows[x])-2)) && (character.at(0)<=(objects.at(rows[x])+2))) && ((character.at(1)>=(objects.at(cols[x])-2)) && (character.at(1)<=(objects.at(cols[x])+2)))) {
                
                inv_spawn = 1;
                break;
            }
            else
                inv_spawn=0;
        }
        //cout<<"\n"<<inv_spawn;                            re-spawn indicator
        if(inv_spawn==1) {
            //cout<<"new spawn"<<endl;
            for(int j=0;j<2;j++) {
                character[j]=rand()%15+1;
                //cout<<"\n"<<character[j]<<"\n";           new location metrics
            }
        }
    }while(inv_spawn!=0);
    return character;
}

vector<int> Move_PC(vector<int>PC_pos) {
    char keyPress;
    cout<<"Where next? (press q to exit the game): ";
    cin>>keyPress;
    if(keyPress=='w')
        PC_pos.at(0)-=1;
    else if(keyPress=='a')
        PC_pos.at(1)-=1;
    else if(keyPress=='s')
        PC_pos.at(0)+=1;
    else if(keyPress=='d')
        PC_pos.at(1)+=1;
    else if(keyPress=='q')
        PC_pos.at(1)=-99;
    
    return PC_pos;
}

vector<int> Move_Musk(vector<int> objects){
    int coord = rand()%4;
    if(coord==0)
        objects.at(6)+=2;
    else if(coord==1)
        objects.at(6)-=2;
    else if(coord==2)
        objects.at(7)+=2;
    else if(coord==3)
        objects.at(7)-=2;
    return objects;
}

void Titles() {
    cout<<"\nWelcome to SpaceX. You are assigned to save the Roadster from being propelled into the space.\n"
        <<"You have to find the roadster and get away with. However the compound is dark and you have to follow your instincts."
        <<"\nThe compund is 15x15 units of area and you can move 1 unit at a time in 1 direction only.\n"
        <<"The compound also has Elon Musk sleeping somewhere in 1 unit and if you reach as close as 2 square units away from him, he will wake up and start moving randomly, 2 steps at a time (because its his own factory, duh)."
        <<"\nSince the compound is dark, you can get into one of the 2 other cars as well (a Yugo and a Pinto)."
        <<"\nIf you get into any of the other car, you'll be trapped and sent to space. This will also happen if Elon finds you."
    <<"\n\nw: to move up the column\ns: to move down the column\na: to move left in a row\nd: to move right in a column."
        <<"\nFIND THE ROADSTER. GOOD LUCK.\n\n";
}

int main() {
    bool newgame=false;
    int roadster=0, starman=0;
    do{
        srand(time(NULL));
        system("CLS");
        Titles();
        vector<int> objects = Object_Spawn();
        /*for(int j=0;j<8;j++)                                      //All objects' metrics
            cout<<objects[j]<<endl;*/
        
        cout<<"Starting coordinates:\n";
        vector<int> character = PC_Spawn(objects);
        for(int j=0;j<2;j++)
            cout<<character[j]<<endl;
    
        char quit='n',another='n';
        int lives = 2, move_Counter=0;
        char musk_Awake = 'n';
        bool proximity=false;
        bool muskimity=false;
    
        while(quit!='y'){
            bool fault=false;
            if(lives==2) {
            if((character.at(0)>=(objects.at(6)-2))&&(character.at(0)<=(objects.at(6)+2))&&(character.at(1)>=(objects.at(7)-2))&&(character.at(1)<=(objects.at(7)+2))) {                    //Waky-waky, Musk
                    cout<<"YOU HAVE AWAKEN ELON MUSK!\n";
                    lives=1;
                    musk_Awake = 'y';
                    continue;
                    //character = Move_PC(character);                           //PC metrics
                }
                do{
                    character = Move_PC(character);                             //move the player
                    if(character.at(1)==-99)
                        exit(0);
                    
                    if(character.at(0)>15) {
                        fault=true;
                        cout<<"Going out of bounds!"<<endl;
                        character.at(0)-=1;
                    }
                    else if(character.at(1)>15) {
                        fault=true;
                        cout<<"Going out of bounds!"<<endl;
                        character.at(1)-=1;
                    }
                    else if(character.at(0)<1) {
                        fault=true;
                        cout<<"Going out of bounds!"<<endl;
                        character.at(0)+=1;
                    }
                    else if(character.at(1)<1) {
                        fault=true;
                        cout<<"Going out of bounds!"<<endl;
                        character.at(1)+=1;
                    }
                    else
                        fault=false;
                }while(fault!=false);
                move_Counter+=1;
                //PARTNER IN CRIME, COMMUNICATE TO SAVE (STEAL) A TESLA
                if((character.at(0)>=(objects.at(0)-2))&&(character.at(0)<=(objects.at(0)+2))&&(character.at(1)>=(objects.at(1)-2))&&(character.at(1)<=(objects.at(1)+2))) {
                        cout<<"\nRoadster in your proximity, chief.";
                        proximity=true;
                }
                else if((proximity==true) && ((character.at(0)>=(objects.at(0)-3))&&(character.at(0)<=(objects.at(0)+3))&&(character.at(1)>=(objects.at(1)-3))&&(character.at(1)<=(objects.at(1)+3)))) {
                    cout<<"\nI think you should turn around...";
                    proximity=false;
                }
                
                //The only good ending: YOU GET THE ROADSTER
                if((character.at(0)==objects.at(0))&&(character.at(1)==objects.at(1))) {
                    cout<<"\nAWESOME! YOU FOUND THE ROADSTER! ELON MUSK AIN'T BORED ANYMORE...\n";
                    cout<<"Moves made: "<<move_Counter<<endl;
                    roadster+=1;
                    cout<<"You have saved the roadster: "<<roadster<<" times."<<endl;
                    cout<<"You have become the starman: "<<starman<<" times."<<endl;
                    cout<<"Another game? (y/n)";
                    cin>>another;
                    if(another=='y') {
                        newgame=true;
                        break;
                    }
                    else
                        exit(0);
                }
                
                //Bad ending 1: YOU FOUND THE YUGO
                if((character.at(0)==objects.at(2))&&(character.at(1)==objects.at(3))) {
                    cout<<"\nWHOOPS, YOU GOT INTO THE YUGO. ELON MUSK MAKES YOU THE STARMAN...\n";
                    cout<<"Moves made: "<<move_Counter<<endl;
                    starman+=1;
                    cout<<"You have saved the roadster: "<<roadster<<" times."<<endl;
                    cout<<"You have become the starman: "<<starman<<" times."<<endl;
                    cout<<"Another game? (y/n)";
                    cin>>another;
                    if(another=='y') {
                        newgame=true;
                        break;
                    }
                    else
                        exit(0);
                }
                
                //Bad ending 2: YOU FOUND THE PINTO
                if((character.at(0)==objects.at(4))&&(character.at(1)==objects.at(5))) {
                    cout<<"\nWHOOPS, YOU GOT INTO THE PINTO. ELON MUSK MAKES YOU THE STARMAN...\n";
                    cout<<"Moves made: "<<move_Counter<<endl;
                    starman+=1;
                    cout<<"You have saved the roadster: "<<roadster<<" times."<<endl;
                    cout<<"You have become the starman: "<<starman<<" times."<<endl;
                    cout<<"Another game? (y/n)";
                    cin>>another;
                    if(another=='y') {
                        newgame=true;
                        break;
                    }
                    else
                        exit(0);
                }
            }
            
            if(lives==1) {
                //Worst ending: ELON FOUND YOU
                if((character.at(0)==objects.at(6))&&(character.at(1)==objects.at(7))) {
                    cout<<"\nSAD. ELON FOUND YOU (PLUS HE HAS HIS FLAMETHROWER WITH HIM. AND HE IS ANGRY). YOU BECOME THE STARMAN...\n";
                    cout<<"Moves made: "<<move_Counter<<endl;
                    starman+=1;
                    cout<<"You have saved the roadster: "<<roadster<<" times."<<endl;
                    cout<<"You have become the starman: "<<starman<<" times."<<endl;
                    cout<<"Another game? (y/n)";
                    cin>>another;
                    if(another=='y') {
                        newgame=true;
                        break;
                    }
                    else
                        exit(0);
                }
                do{
                    character = Move_PC(character);                             //Run for your life, PC
                    
                    if(character.at(1)==-99)
                        exit(0);
                    
                    if(character.at(0)>15) {
                        fault=true;
                        cout<<"Going out of bounds!"<<endl;
                        character.at(0)-=1;
                    }
                    else if(character.at(1)>15) {
                        fault=true;
                        cout<<"Going out of bounds!"<<endl;
                        character.at(1)-=1;
                    }
                    else if(character.at(0)<1) {
                        fault=true;
                        cout<<"Going out of bounds!"<<endl;
                        character.at(0)+=1;
                    }
                    else if(character.at(1)<1) {
                        fault=true;
                        cout<<"Going out of bounds!"<<endl;
                        character.at(1)+=1;
                    }
                    else if(character.at(1)==-99) {
                        
                    }
                    else
                        fault=false;
                }while(fault!=false);
                move_Counter+=1;
                
                do{
                    objects = Move_Musk(objects);                             //Elon is BORED (wink, wink)
                    if(objects.at(6)>15) {
                        fault=true;
                        objects.at(6)-=1;
                    }
                    else if(objects.at(7)>15) {
                        fault=true;
                        objects.at(7)-=1;
                    }
                    else if(objects.at(6)<1) {
                        fault=true;
                        objects.at(6)+=1;
                    }
                    else if(objects.at(7)<1) {
                        fault=true;
                        objects.at(7)+=1;
                    }
                    else
                        fault=false;
                }while(fault!=false);
            }
            
            //PARTNER IN CRIME, COMMUNICATE TO SAVE (STEAL) A TESLA
            if((character.at(0)>=(objects.at(0)-2))&&(character.at(0)<=(objects.at(0)+2))&&(character.at(1)>=(objects.at(1)-2))&&(character.at(1)<=(objects.at(1)+2))) {
                cout<<"\nRoadster in your proximity, chief.";
                proximity=true;
            }
            else if((proximity==true) && ((character.at(0)>=(objects.at(0)-3))&&(character.at(0)<=(objects.at(0)+3))&&(character.at(1)>=(objects.at(1)-3))&&(character.at(1)<=(objects.at(1)+3)))) {
                cout<<"\nI think you should turn around...";
                proximity=false;
            }
            
            //LOOKS LIKE MUSK IS NEARBY...
            if((character.at(0)>=(objects.at(6)-2))&&(character.at(0)<=(objects.at(6)+2))&&(character.at(1)>=(objects.at(7)-2))&&(character.at(1)<=(objects.at(7)+2))) {
                cout<<"\nElon Musk in close proximity. RUN.";
                muskimity=true;
            }
            
            else if((muskimity==true) && ((character.at(0)>=(objects.at(6)-2))&&(character.at(0)<=(objects.at(6)+2))&&(character.at(1)>=(objects.at(7)-2))&&(character.at(1)<=(objects.at(7)+2)))) {
                cout<<"\nElon Musk is close but Roadster is close too! What are you gonna do?";
            }
            
            //The only good ending: YOU GET THE ROADSTER
            if((character.at(0)==objects.at(0))&&(character.at(1)==objects.at(1))) {
                cout<<"\nAWESOME! YOU FOUND THE ROADSTER! ELON MUSK AIN'T BORED ANYMORE...\n";
                cout<<"Moves made: "<<move_Counter<<endl;
                roadster+=1;
                cout<<"You have saved the roadster: "<<roadster<<" times."<<endl;
                cout<<"You have become the starman: "<<starman<<" times."<<endl;
                cout<<"Another game? (y/n)";
                cin>>another;
                if(another=='y') {
                    newgame=true;
                    break;
                }
                else
                    exit(0);
            }
            
            //Bad ending 1: YOU FOUND THE YUGO
            if((character.at(0)==objects.at(2))&&(character.at(1)==objects.at(3))) {
                cout<<"\nWHOOPS, YOU GOT INTO THE YUGO. ELON MUSK MAKES YOU THE STARMAN...\n";
                cout<<"Moves made: "<<move_Counter<<endl;
                starman+=1;
                cout<<"You have saved the roadster: "<<roadster<<" times."<<endl;
                cout<<"You have become the starman: "<<starman<<" times."<<endl;
                cout<<"Another game? (y/n)";
                cin>>another;
                if(another=='y') {
                    newgame=true;
                    break;
                }
                else
                    exit(0);
            }
            
            //Bad ending 2: YOU FOUND THE PINTO
            if((character.at(0)==objects.at(4))&&(character.at(1)==objects.at(5))) {
                cout<<"\nWHOOPS, YOU GOT INTO THE PINTO. ELON MUSK MAKES YOU THE STARMAN...\n";
                cout<<"Moves made: "<<move_Counter<<endl;
                starman+=1;
                cout<<"You have saved the roadster: "<<roadster<<" times."<<endl;
                cout<<"You have become the starman: "<<starman<<" times."<<endl;
                cout<<"Another game? (y/n)";
                cin>>another;
                if(another=='y') {
                    newgame=true;
                    break;
                }
                else
                    exit(0);
            }
            cout<<endl<<character.at(0)<<","<<character.at(1)<<endl;
            //cout<<"Musk: "<<objects.at(6)<<","<<objects.at(7)<<endl;          Elon Musk's metrics
        }
    }while(newgame!=false);
    return 0;
}
