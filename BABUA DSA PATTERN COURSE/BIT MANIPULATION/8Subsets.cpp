//  Uber   Apple   Adobe   Amazon   Google   Reddit   Twitter   Facebook   Bloomberg   Microsoft 

// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result;
    int total = (1<<n);
    for(int mask=0;mask<total;mask++){
        vector<int> subsets;
        for(int i=0;i<n;i++)
            if(mask&(1<<i)) subsets.push_back(nums[i]);
        result.push_back(subsets);
    }
    return result;
}


int main(){
    int n;
    vector<int> nums;
    while(cin>>n)
        nums.push_back(n);

    vector<vector<int>> result = subsets(nums);
    cout<<"[";
    for(vector<int> &i : result){
        cout<<"[";
        for(int j=0;j<i.size();j++){
            cout<<i[j];
            if(j!=i.size()-1)
                cout<<",";
        }
        cout<<"]";
    }
    cout<<"]";
    return 0;
}