//  Facebook  

// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
// Example 2:

// Input: nums = [5], k = 1
// Output: 5.00000

#include<iostream>
#include<vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double maxAvg = -1e18;
    int i=0,j=0,n=nums.size();
    double sum = 0.00000;
        
    while(j<n){
        sum += nums[j];
        if(j-i+1==k){
            maxAvg = max(maxAvg,sum/k);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    return (maxAvg == -1e18) ? 0.00000 : maxAvg; 
}

int main(){
    vector<int> nums;
    int n;
    while(cin>>n){
        nums.push_back(n);
        if(cin.peek()=='\n') break;
    }
    int k = nums.back();
    nums.pop_back();
    cout<<findMaxAverage(nums,k);
    return 0;
}