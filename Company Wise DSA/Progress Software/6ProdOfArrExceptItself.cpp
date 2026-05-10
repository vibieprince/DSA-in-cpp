//  Uber   Asana   Apple   Adobe   Amazon   Oracle   Facebook   Microsoft   Bloomberg  

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf1(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixProduct(n), suffixProduct(n);
        prefixProduct[0] = nums[0];
        suffixProduct[n-1] = nums[n-1];

        for(int i=1;i<n;i++)
            prefixProduct[i] = prefixProduct[i-1] * nums[i];

        for(int i=n-2;i>=0;i--)
            suffixProduct[i] = suffixProduct[i+1] * nums[i];
        
        vector<int> ans(n);
        ans[0] = suffixProduct[1];
        ans[n-1] = prefixProduct[n-2];

        for(int i=1;i<n-1;i++)
            ans[i] = prefixProduct[i-1] * suffixProduct[i+1];
        
        return ans;
    }

    // Constant Space
    vector<int> productExceptSelf2(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int leftProduct = 1,rightProduct = 1;
        for(int i=0;i<n;i++){
            ans[i] = leftProduct;
            leftProduct *= nums[i];
        }

        for(int i = n-1;i>=0;i--){
            ans[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,3,4};
    vector<int> ans = obj.productExceptSelf1(nums);
    for(int &i : nums)
        cout<<i<<" ";
    return 0;
}