#include<iostream>
using namespace std;
long long squareRootInteger(int n){
    int low = 0,high = n,ans = -1;
    long long mid = low + (high-low)/2;
    while(low<=high){
        if(mid*mid==n)
           return mid;
        else if(mid*mid>n)
           high = mid-1;
        else{
            ans = mid;
            low = mid+1;
        }
        mid = low + (high-low)/2;
    }
    return ans;
}
double morePrecision(int n,int tempSol,int precision =3){
    double factor = 1;
    double ans = tempSol;
    for(int i=0;i<precision;i++){
        factor /= 10;
        for(double j=ans;j*j<n;j= j+factor){
            ans = j;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    int tempSol = squareRootInteger(n);
    // cout<<"Answer is : "<<morePrecision(n,tempSol,5)<<endl;
    cout<<"Answer is : "<<morePrecision(n,tempSol)<<endl;
}