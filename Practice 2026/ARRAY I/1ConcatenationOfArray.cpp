// Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

// Specifically, ans is the concatenation of two nums arrays.

// Return the array ans.
#include<iostream>
#include<vector>
using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<n;i++)
        nums.push_back(nums[i]);
    return nums;
}

int main() {
    int n;
    cin >> n;  // size of array

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];  // input elements
    }

    vector<int> result = getConcatenation(nums);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}