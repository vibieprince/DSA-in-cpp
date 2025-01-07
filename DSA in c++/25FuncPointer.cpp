#include<iostream>
using namespace std;
void print(int *p){
    cout<<*p<<endl;
}
void update(int *p){
    // p = p+1;
    // cout<<"Inside "<<p<<endl;
    *p = *p + 1;
}
int getSum(int *arr,int n){
    cout<<sizeof(arr)<<endl;
    int sum = 0;
    for(int i=0;i<n;i++)
    //    sum += arr[i];
       sum += i[arr];
    return sum;
}
int main(){
    int val = 5;
    int *p = &val;
    cout<<"Before "<<*p<<endl;
    // print(p);
    update(p);
    cout<<"After "<<*p<<endl;

    int arr[10] = {1,2,3,4,5};
    // cout<<"Sum is "<<getSum(arr,5)<<endl;
    cout<<"Sum is "<<getSum(arr+3,5)<<endl;
    return 0;
}