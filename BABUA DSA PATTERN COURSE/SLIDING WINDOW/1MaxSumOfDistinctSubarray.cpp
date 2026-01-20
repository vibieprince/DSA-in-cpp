//  Amazon   Facebook  

// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {
    int i=0,j=0,n = nums.size();
    long long maxSum= 0;
    long long sum = 0;
    unordered_set<int> set;
    while(j<n){
        while(set.count(nums[j])){
            set.erase(nums[i]);
            sum -= nums[i++];
        }

        set.insert(nums[j]);
        sum += nums[j];

        if(j-i+1==k){
            maxSum = max(maxSum,sum);
            set.erase(nums[i]);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    return maxSum;
}

int main(){
    vector<int> nums;
    int x;
    while(cin>>x){
        nums.push_back(x);
        if(cin.peek()=='\n');
    }

    int k = nums.back();
    nums.pop_back();

    cout<<maximumSubarraySum(nums,k);
}