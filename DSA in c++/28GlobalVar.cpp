#include<iostream>
using namespace std;

int score = 15; // Global variable ---> Generally we don't use Global variables [BAD PRACTICE]
void a(int &i){ // reference variable
    cout<<score<<" in a"<<endl;
    char ch = 'a'; // local variable for function a
    cout<<i<<endl;
    // b(i);
}

void b(int &i){
    cout<<score<<" in b "<<endl;
    cout<<i<<endl;
}
int main(){
    int i = 5;
    cout<<score<<" in main"<<endl;
    a(i);
    b(i);
    // {
    //     int i = 3;
    //     cout<<i<<endl;
    // }
    // cout<<i<<endl;
    return 0;
}