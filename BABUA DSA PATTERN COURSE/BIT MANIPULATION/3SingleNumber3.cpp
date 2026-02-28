// Google

// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]
// Example 3:

// Input: nums = [0,1]
// Output: [1,0]

#include<iostream>
#include<vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int groupA = 0;
    int groupB = 0;

    unsigned int xorAll = 0;
    for(int &i : nums)
        xorAll ^= i;
    
    unsigned int mask = xorAll & (~xorAll + 1);

    for(int &i : nums){
        if((mask & i) != 0) // precedence check ()
            groupA ^= i;
        else
            groupB ^= i;
    }

    return {groupA,groupB};
}

int main(){

    int n;
    vector<int> nums;

    while(cin>>n)
        nums.push_back(n);

    vector<int> result = singleNumber(nums);
    cout<<"["<<result[0]<<","<<result[1]<<"]";
    return 0;
}