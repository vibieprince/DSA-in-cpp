//  Apple   Amazon   Google   Facebook   Arcesium   Microsoft   Bloomberg   Goldman Sachs  

// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int minSubArrayLen(int target, vector<int>& nums) {
    long long sum = 0;
    int len = 0,minLength=INT_MAX;
    int i=0,j=0,n=nums.size();
    while(j<n){
        
        sum += nums[j];
        len++;
        
            
        while(sum>=target){
            minLength = min(len,minLength);
            sum -= nums[i];
            i++;
            len--;
        }
        
        j++;
    }
    return (minLength==INT_MAX) ? 0 : minLength;
}

int main(){
    int n;
    vector<int> nums;
    while(cin>>n){
        nums.push_back(n);
        if(cin.peek()=='\n')
            break;
    }

    int target = nums.back();
    nums.pop_back();

    cout<<minSubArrayLen(target,nums);
    return 0;
}