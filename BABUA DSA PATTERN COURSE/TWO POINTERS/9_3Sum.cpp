// Uber   Apple   Adobe   Yahoo   Cisco   Tesla   Amazon   Google   tiktok   VMware   Oracle   Infosys   Facebook   Microsoft   Bloomberg   Qualtrics   ByteDance   Salesforce   Goldman Sachs   Morgan Stanley   American Express   Walmart Global Tech  

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void threeSumHelper(vector<vector<int>> &result,int f,vector<int>&nums){
    int i=f+1;
    int j = nums.size()-1;

    while(i<j){
        int sum = nums[f] + nums[i] + nums[j];
        if(sum>0)
            j--;
        else if(sum<0)
            i++;
        else{
            result.push_back({nums[f],nums[i],nums[j]});
            i++;
            j--;

            // Now avoid duplicates
            while(i<j && nums[i] == nums[i-1])
                i++;
            
            while(i<j && nums[j] == nums[j+1])
                j--;
        }
    }
}
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    for(int f=0;f<nums.size();f++){
        if(nums[f]>0) break;
        if(f==0 || nums[f] != nums[f-1])
            threeSumHelper(result,f,nums);
    }
    return result;
}

int main() {
    vector<int> nums;
    int n;

    // Read input till EOF
    while (cin >> n)
        nums.push_back(n);

    vector<vector<int>> ans = threeSum(nums);

    // Print in LeetCode format
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        cout << ans[i][0] << "," << ans[i][1] << "," << ans[i][2];
        cout << "]";
        if (i != ans.size() - 1) cout << ",";
    }
    cout << "]";

    return 0;
}
