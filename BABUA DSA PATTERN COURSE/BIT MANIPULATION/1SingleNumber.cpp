//  Uber   Adobe   Apple   Amazon   Google   Facebook   Microsoft   Bloomberg   Atlassian  
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,1]

// Output: 1

// Example 2:

// Input: nums = [4,1,2,1,2]

// Output: 4

// Example 3:

// Input: nums = [1]

// Output: 1
#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int num = nums[0];
    for(int i=1;i<nums.size();i++)
        num ^= nums[i];
    return num;
}

int main(){
    int n;
    vector<int> nums;

    while(cin>>n)
        nums.push_back(n);

    cout<<singleNumber(nums);
    return 0;
}