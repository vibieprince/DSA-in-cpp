// Leetcode 560

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++)
            prefixSum[i] = nums[i] + prefixSum[i-1];
        
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            int val = prefixSum[i] - k;

            if(prefixSum[i]==k) 
                count++;

            if(map.find(val)!=map.end())
                count += map[val];
            
            map[prefixSum[i]]++;
        }
        return count;
    }
};