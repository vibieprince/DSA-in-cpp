//Given a binary array nums, return the maximum number of consecutive 1's in the array.
#include<iostream>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxOnes = 0;
    int count = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1) count++;
        else
            count = 0;
        maxOnes = max(maxOnes,count);
    }
    return maxOnes;
}

int main(){
    int n;
    vector<int> nums;
    while(cin>>n)
        nums.push_back(n);
    n = findMaxConsecutiveOnes(nums);
    cout<<n;
}