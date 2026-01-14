// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

// Input: nums = [1,2,2,4]
// Output: [2,3]

#include<iostream>
#include<vector>
using namespace std;
vector<int> findErrorNums(vector<int>& nums) {
    vector<int> result;
    for(int i=0;i<nums.size();i++){
        if(nums[abs(nums[i])-1]<0) {
            result.push_back(abs(nums[i]));
            continue;
        }
        nums[abs(nums[i])-1] *= -1;
    }
    for(int i=0;i<nums.size();i++)
        if(nums[i]>0){
            result.push_back(i+1);
            break;
    }
    return result;
}
// You visit the index abs(nums[i]) - 1
// If it is already negative → it means you've visited it before
// If a number was never visited, its index was never marked negative.
// So: The index that stays positive → missing number = index + 1
int main(){
    vector<int> nums;
    int n;
    while(cin>>n)
        nums.push_back(n);
    nums = findErrorNums(nums);
}