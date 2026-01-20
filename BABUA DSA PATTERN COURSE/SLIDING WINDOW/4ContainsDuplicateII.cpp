//  Uber   Adobe   Google   Amazon   Facebook   Bloomberg   Microsoft  

// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int i=0,j=0,n=nums.size();
    unordered_set<int> set;
    while(j<n){
        if(set.count(nums[j]))
            return true;
        
        set.insert(nums[j]);
        
        if(j-i>=k){
            set.erase(nums[i]);
            i++;
        }
        j++;
    }
    return false;
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
    cout<<(containsNearbyDuplicate(nums,k)? "true" : "false");
}