// Adobe   Apple   Yahoo   Amazon   Google   Microsoft 

// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

// The tests are generated such that there is exactly one solution. You may not use the same element twice.

// Your solution must use only constant extra space.

 

// Example 1:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i=0,j=numbers.size()-1;
    while(i<j){
        int sum = numbers[i]+numbers[j];
        if(sum==target) return {i+1,j+1};
        else if(sum>target)
            j--;
        else
            i++;
    }
    return {};
}

int main(){
    int n;
    vector<int> numbers;
    while(cin>>n)
        numbers.push_back(n);
    int target = numbers.back();
    numbers.pop_back();

    vector<int> ans = twoSum(numbers,target);

    cout<<"["<<ans[0]<<","<<ans[1]<<"]";
}