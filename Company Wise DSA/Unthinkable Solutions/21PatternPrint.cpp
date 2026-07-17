#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x = (i<=n/2 ? i : n-i-1);
        int stars;
        if(x%2)
            stars = x+1;
        else 
            stars = n - x;
        for(int j=0;j<stars;j++)
            cout<<"* ";
        cout<<endl;
    }
    return 0;
}