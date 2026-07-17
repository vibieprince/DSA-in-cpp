#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int maxSum = INT_MIN,currSum=0;

    for(int i=0;i<n;i++){
        currSum += arr[i];
        maxSum = max(maxSum,currSum);
        if(currSum<0)
            currSum = 0;
    }
    cout<<maxSum;
    return 0;
}