//  Uber   Apple   Adobe   Cisco   PayTM   Amazon   Google   Shopee   VMware   Oracle   Samsung   Infosys   LinkedIn   Facebook   JPMorgan   Docusign   Microsoft   Bloomberg   ByteDance   Salesforce   ServiceNow   Goldman Sachs   Walmart Global Tech  

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
 

// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for(int i=0;i<nums.size();i++){
            if(currSum<0)
                currSum = 0;
            currSum += nums[i];
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<obj.maxSubArray(nums);
    return 0;
}