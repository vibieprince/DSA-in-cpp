//  TCS   Apple   Amazon   Google   Myntra   Tailnode   ShareChat   MAQ Software   Testbook.com   Goldman Sachs   ZS Associates 

// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3

// Example 2:
// Input: nums = [0,1,0,1,0,1,99]
// Output: 99

#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for(int bit = 0;bit<32;bit++){
        int temp = (1<<bit);
        int count0 = 0;
        int count1 = 0;
        for(int &num : nums){
            if((num&temp)==0)
                count0++;
            else
                count1++;
        }
        if(count1%3==1)
            result |= temp;
    }
    return result;
}

int main(){
    int n;
    vector<int> nums;

    while(cin>>n)
        nums.push_back(n);

    cout<<singleNumber(nums);
    return 0;
}