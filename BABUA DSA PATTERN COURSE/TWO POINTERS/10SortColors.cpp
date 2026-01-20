//  Grab   Uber   Adobe   Intel   Amazon   VMware   Nvidia   Facebook   Microsoft   Salesforce  

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int i = 0,j=nums.size()-1,k=0;

    while(k<=j){
        if(nums[k]==1) k++;
        else if(nums[k]==2) 
            swap(nums[k],nums[j--]);
        else 
            swap(nums[k++],nums[i++]);
    }
}

int main(){
    vector<int> nums;
    int x;
    while(cin>>x)
        nums.push_back(x);
    sortColors(nums);
    return 0;
}