#include <iostream>
using namespace std;

void print(int *arr,int n,int start = 0){ //Now start is made a default argument
    for(int i=start;i<n;i++){ // can make all parameters default
        cout<<arr[i]<<endl;
    }
}
int main(){
    int arr[] = {1,4,7,8,9};
    // print(arr,5,2);
    print(arr,5); // default argument used 

    // default argument should always be the rightmost

    return 0;
}