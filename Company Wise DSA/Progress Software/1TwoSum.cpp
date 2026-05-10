//  IBM   Uber   Zoho   Visa   Dell   Zoom   Adobe   Apple   Yahoo   Intel   Amazon   Google   Oracle   Paypal   Intuit   Zillow   Zomato   Spotify   Expedia   Samsung   Facebook   JPMorgan   Microsoft   Bloomberg   Accenture   Salesforce   Goldman Sachs   Morgan Stanley   American Express   Walmart Global Tech  

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i])!=map.end())
                return {map[target-nums[i]],i};
            map[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    Solution obj;
    vector<int> nums = {2,7,11,15};
    vector<int> ans = obj.twoSum(nums,9);
    cout<<ans[0]<<ans[1];
    return 0;
}