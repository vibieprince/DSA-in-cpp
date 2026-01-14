// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
// Return the array in the form [x1,y1,x2,y2,...,xn,yn].

#include<vector>
#include<iostream>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    for(int i=0;i<n;i++)
        nums[i] = nums[i]  | (nums[i+n] << 10); // pack first and second number

    for(int i = n-1;i>=0;i--){// because constraint is about 1000 only in binary 1000 fits with 10 bits since 2^10 = 1024
        int x = nums[i] & 1023; // 1023 in binary is 1111111111 acts as a mask
        int y = nums[i] >> 10; // recover the second number
        nums[2*i] = x;
        nums[2*i+1] = y;
    }
    return nums;
}

int main(){
    int n;
    vector<int> nums;
    while(cin>>n)
        nums.push_back(n);
    nums = shuffle(nums,nums.size()/2);
    for(int i:nums)
        cout<<i<<" ";
}