#include <iostream>
using namespace std;
typedef struct{
    int max;
    int min;
} MaxMin;
MaxMin findMaxMin(int arr[],int n){
    MaxMin result;
    result.max = arr[0];
    result.min = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>result.max)
           result.max = arr[i];
        if(arr[i]<result.min)
          result.min = arr[i];
    }
    return result;
}
void update(int arr[],int n){
    arr[0] = 120;
    cout<<"Inside the function ";
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
    cout<<endl;
}
void printSum(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++)
       sum += arr[i];
    cout<<sum<<endl;
}
bool search(int arr[],int n,int key){
    for(int i=0;i<n;i++)
        if(arr[i]==key)
           return true;
    return false;
}
void reverseArray(int arr[],int n){
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-1-i]);
    }
}
/*
void reverseArray(int arr[],int n){
    int s = 0;
    int e = n-1;
    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}
*/

void swapAlternate(int arr[],int n){
    for(int i=0;i<n-1;i++)
       swap(arr[i],arr[i++]);
}
int main(){
    // int arr[100] = {0}; // all element initialised by 0
    // int arr[100] = {1}; // here all element are not initialised by 1
    // int arr[100]; // integer array
    // fill_n(arr,100,-24); // this initalises every element as -24
    // for(int i=0;i<100;i++){
    //     cout<<arr[i]<<" ";
    // }

    /*
    int array[15] = {3,5}; // rest of the location automatically populates 0
    char ch[5]; //character array
    double firstDouble[5]; // double array
    float firstFloat[5]; // float array
    bool firstBool[5]; // boolean array
    */

    /*
    int arr[5] = {4,57,5,3,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    MaxMin result = findMaxMin(arr,n);
    cout<<"Maximum : "<<result.max<<" Minimum : "<<result.min;
    */
    
    int arr[7] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    // update(arr,3);
    // cout<<"Outside the function "<<endl;
    // for(int i=0;i<n;i++)
    //   cout<<arr[i]<<" "; // output shows that update() function actually updates the real array unlike it's copy like variables
    
    // if(search(arr,3,12))
    //   cout<<"Found";
    // else  
    //   cout<<"Not found";
    // reverseArray(arr,n);
    swapAlternate(arr,n);
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    return 0;
}