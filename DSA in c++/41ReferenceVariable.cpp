#include<iostream>
using namespace std;
void update1(int n){
    n++;
}
void update2(int &n){
    n++;
}
// int &func(int a){
//     int num = a;     ----> Bad Practice
//     int &ans = num;
//     return ans;
// }
// int *fun(int n){
//     int * ptr = &n; -----> Bad Practice
//     return ptr;
// }
int main(){
    int i = 5;
    int &j = i;
    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++; // memory same hai name different hain
    cout<<i<<endl;
    cout<<j<<endl;
    cout<<endl;
    int n = 5;
    cout<<"Before "<<n<<endl;
    // update1(n); // pass by value mein nayi memory create hoti hai
    update2(n); // pass by reference mein nayi memory create nhi hoti
    cout<<"After "<<n<<endl;
    cout<<endl;
    // func(n);
    // cout<<fun(n);
    return 0;
}