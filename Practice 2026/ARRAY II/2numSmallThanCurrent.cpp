// Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

#include<iostream>
#include<vector>
using namespace std;
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> freq(101,0);
    for(int x : nums)
        freq[x]++;
    for(int i=1;i<101;i++)
        freq[i] += freq[i-1];
    vector<int> ans(nums.size());
    for(int i=0;i<nums.size();i++){
        int x = nums[i];
        ans[i] = (x==0 ? 0 : freq[x-1]);
    }
    return ans;
}

int main(){
    vector<int> nums;
    int n;
    while(cin>>n)
        nums.push_back(n);
    nums = smallerNumbersThanCurrent(nums);
}