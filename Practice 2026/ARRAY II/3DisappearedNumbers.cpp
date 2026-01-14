// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

#include<iostream>
#include<vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(n+1,0);
    for(int x : nums)
        freq[x]++;
    vector<int> ans;
    for(int i=1;i<=n;i++)
        if(freq[i]==0) ans.push_back(i);
    return ans;
}

// vector<int> findDisappearedNumbers(vector<int>& nums) {
//     vector<int> result;
//     for(int i=0;i<nums.size();i++){
//         int index = abs(nums[i]) -1;
//         if(nums[index]>0) nums[index] = -nums[index];
//     }
//     for(int i=0;i<nums.size();i++)
//         if(nums[i]>0) result.push_back(i+1);
//     return result;
// }

int main(){
    vector<int> nums;
    int n;
    while(cin>>n)
        nums.push_back(n);
    nums = findDisappearedNumbers(nums);
}