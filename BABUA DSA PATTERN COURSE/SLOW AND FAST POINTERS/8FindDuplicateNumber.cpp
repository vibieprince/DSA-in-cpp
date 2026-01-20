// TCS   OLA   Zoho   eBay   Uber   Uber   Paytm   Adobe   Cisco   Yahoo   Apple   Amazon   PayPal   Splunk   VMware   Google   DE-Shaw   Expedia   Nutanix   Virtusa   Flipkart   HashedIn   Facebook   Qualcomm   Bloomberg   Capgemini   Microsoft   BNY Mellon   Housing.com   PegaSystems   Goldman Sachs   Unthinkable Solution  


// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3

#include<iostream>
#include<vector>
using namespace std;


int findDuplicate(vector<int>& nums) {
    int slow = nums[0],fast=nums[0];
    while(true){
        slow = nums[slow];
        fast = nums[nums[fast]];

        if(slow==fast)
            break;
    }
    slow = nums[0];
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow; // not nums[slow]
}

int main(){
    int n;
    vector<int> nums;
    while(cin>>n){
        nums.push_back(n);
        if(cin.peek()=='\n') break;
    }
    cout<<findDuplicate(nums);
}