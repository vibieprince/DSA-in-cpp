#include<iostream>
using namespace std;

int main(){
    int money = 13234;
    int note = 0;
    switch(1){
        case 1:
        note = money/100;
        money = money - (100*note);
        cout<<note<<" Rs.100 note required"<<endl;

        case 2:
        note = money/50;
        money = money - (50*note);
        cout<<note<<" Rs.50 note required"<<endl;

        case 3:
        note = money/20;
        money = money - (20*note);
        cout<<note<<" Rs.20 note required"<<endl;

        case 4:
        note = money / 1;
        money = money - (1*note);
        cout<<note<<" Rs.1 note required"<<endl;
    }
}