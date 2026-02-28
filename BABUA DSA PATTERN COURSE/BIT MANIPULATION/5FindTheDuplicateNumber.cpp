//  TCS   OLA   Zoho   eBay   Uber   Uber   Paytm   Adobe   Cisco   Yahoo   Apple   Amazon   PayPal   Splunk   VMware   Google   DE-Shaw   Expedia   Nutanix   Virtusa   Flipkart   HashedIn   Facebook   Qualcomm   Bloomberg   Capgemini   Microsoft   BNY Mellon   Housing.com   PegaSystems   Goldman Sachs   Unthinkable Solution  

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [3,3,3,3,3]
// Output: 3

#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size()-1;
    int duplicate = 0;
    for(int bit=0;bit<32;bit++){
        int mask = (1<<bit);
        int baseCount = 0;
        int numsCount = 0;
        for(int i=1;i<=n;i++)
            if(i&mask) baseCount++;
        
        for(int &num : nums)
            if(num & mask) numsCount++;
        
        if(numsCount> baseCount)
            duplicate |= mask;
    }
    return duplicate;
}

int main(){
    int n;
    vector<int> nums;

    while(cin>>n)
        nums.push_back(n);

    cout<<findDuplicate(nums);
    return 0;
}