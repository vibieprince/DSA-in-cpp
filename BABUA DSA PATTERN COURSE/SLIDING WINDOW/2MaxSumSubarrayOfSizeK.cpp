// Oyo Rooms

// Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

// Note: A subarray is a contiguous part of any given array.

// Examples:

// Input: arr[] = [100, 200, 300, 400], k = 2
// Output: 700
// Explanation: arr2 + arr3 = 700, which is maximum.
// Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
// Output: 39
// Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.
// Input: arr[] = [100, 200, 300, 400], k = 1
// Output: 400
// Explanation: arr3 = 400, which is maximum

#include<vector>
#include<iostream>
using namespace std;

int maxSubarraySum(vector<int>& arr, int k) {
    // code here
    int i=0,j=0,sum=0,maxSum=0;
    
    while(j<arr.size()){
        sum += arr[j];
        
        if(j-i+1==k){
            maxSum = max(maxSum,sum);
            sum -= arr[i];
            i++;
        }
        
        j++;
    }
    return maxSum;
}

int main(){
    vector<int> arr;
    int x;
    while(cin>>x){
        arr.push_back(x);
        if(cin.peek()=='\n');
    }

    int k = arr.back();
    arr.pop_back();

    cout<<maxSubarraySum(arr,k);
}