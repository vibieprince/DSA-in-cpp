#include<iostream>
using namespace std;
int getSum(int *arr,int n){
    int sum = 0;
    for(int i=0;i<n;i++)
       sum += arr[i];
    return sum;
}
int main(){
    int n;
    cin>>n;

    //Variable size array
    int *arr = new int[n];  

    //Taking inputs in array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<getSum(arr,n);

    // case 1 | Static
    while(true)
      int i = 5;
    //gets free after reaching end

    // case 2 | Dynamic ---> Bad Practice
    // while(true)
    //   int *ptr = new int;
    // but here in heap no memory gets freed
    // use delete keyword to free memory
    // delete ptr;
    // delete []arr;
}