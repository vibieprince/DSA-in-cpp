//  MAQ   Uber   Adobe   Amazon   Factset   Infosys   Fourkites   Deutsche Bank 

// The frequency of an element is the number of times it occurs in an array.

// You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

// Return the maximum possible frequency of an element after performing at most k operations.

 

// Example 1:

// Input: nums = [1,2,4], k = 5
// Output: 3
// Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
// 4 has a frequency of 3.
// Example 2:

// Input: nums = [1,4,8,13], k = 5
// Output: 2
// Explanation: There are multiple optimal solutions:
// - Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
// - Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
// - Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    int maxFreq = 0,i=0;
    sort(nums.begin(),nums.end());

    long long sum=0,total;
    for(int j=0;j<nums.size();j++){
        sum += nums[j];
        while(1LL*(j-i+1)*nums[j]-sum>k){
            sum -= nums[i];
            i++;
        }
        maxFreq = max(maxFreq,j-i+1);
    }
    return maxFreq;
}

int main(){
    int n;
    vector<int> nums;
    while(cin>>n){
        nums.push_back(n);
        if(cin.peek()=='\n')
            break;
    }
    int k = nums.back();
    nums.pop_back();
    cout<<maxFrequency(nums,k);
    return 0;
}