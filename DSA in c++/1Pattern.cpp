#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    // i --> row 
    // j --> col 
    int i = 0;
    while(i<n){
        int j = 0;
        while(j<n-1){
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl;
    i = 1;
    while(i<=n){
        int j = 1;
        while(j<4){
            cout<<i<<" ";
            j++;
        }
        i++;
        cout<<endl;
    }
}