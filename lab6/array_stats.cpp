#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int generate(int lim_up){                               //generation of random numbers
    int num_gen = rand()%lim_up;
    return num_gen;
}

void disp_stats(int data[],int amt, int fre_add){       //displaying the statistics
    double sum=fre_add;
    int max = data[0], min = data[0];
    //for(int i=0;i<lim_up;i++)
       // sum+=data[i];
    cout<<"\nSum = "<<sum;
    cout<<"\nMean = "<<(sum/amt);
    
    for(int j=0;j<amt;j++)
        if(data[j]>max)
            max=data[j];
    cout<<"\nMax Value: "<<max;
    
    for(int k=0;k<amt;k++)
        if(data[k]<min)
            min=data[k];
    cout<<"\nMin Value: "<<min<<endl;
    
    
}

void display(int num, int index, int lim_up) {          //displaying the horizontal bar graph
    /*
    for(int i=0;i<lim_up;i++) {
        cout<<i<<"\t\t";
        for(int j=0;j<num;j++)
            cout<<"*";
        cout<<endl; */
    int number;
    
    cout<<index<<"\t\t";                                //scaling and printing the total number of stars
    if(lim_up>70) {
        number = num/2;
        for(int i=0;i<number;i++)
            cout<<"*";
        cout<<num;
    }
    else {
        for(int i=0;i<num;i++)
            cout<<"*";
    cout<<num;
    }
}

void frequency(int amt) {                               //calculating the occurance of each number
    int data[10000],lim_up,x;
    cout<<"Enter the upper limit of the random values: ";
    cin>>lim_up;
    if(lim_up>70)
        cout<<"Each star represents 2 numbers.";
    for(int i=0;i<amt;i++) {                            //for storing in the array -- working
        x = generate(lim_up);
        data[i]=x;
    }
    cout<<endl;
    cout<<"\nIndex\tFrequency Count\n";
    int fre=0,fre_add=0;
    for(int y=0;y<lim_up;y++){
        for(int z=0;z<amt;z++) {                        //for calclating the frequncy and asking the other function to print
            if(y==data[z])
                fre+=1;
        }
            display(fre,y,lim_up);
            cout<<endl;
            fre_add+=fre;
            fre=0;
    }
    disp_stats(data,lim_up,fre_add);
    /*
    cout<<endl<<endl;
    for (int j=0; j<amt; j++)
        cout<<data[j]<<endl;
     */
}

int main() {
    
    srand(time(NULL));
    //int rd = rand()%6+1;
    //cout<<rd<<endl;
    int amt;
    cout<<"Enter the amount of random numbers: ";
    cin>>amt;
    frequency(amt);
    return 0;
}
