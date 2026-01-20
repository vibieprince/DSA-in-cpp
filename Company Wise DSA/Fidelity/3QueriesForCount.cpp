// The task is to determine the number of elements within a specified range in an unsorted array. Given an array of size n, the goal is to count the elements that fall between two given values, i and j, inclusively.
// Examples:

// Input:
// Array: [1, 3, 3, 9, 10, 4]
// Range 1: i = 1, j = 4
// Range 2: i = 9, j = 12

// Output:
// For Range 1: 4
// For Range 2: 2

// Explanation:
// In the first query, the numbers within the range 1 to 4 are 1, 3, 3, and 4.
// In the second query, the numbers within the range 9 to 12 are 9 and 10.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findLowerBound(vector<int> &nums,int x){
    int low = 0;
    int high = nums.size()-1;


    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]>=x)
            high = mid-1;
        else
            low = mid + 1;
    }
    return low;
}

int findUpperBound(vector<int> &nums,int y){
    int low = 0;
    int high = nums.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]<=y)
            low = mid+1;
        else 
            high = mid-1;
    }
    return high;
}

int countElementsInRange(vector<int>&nums,int x,int y){
    return findUpperBound(nums,y) - findLowerBound(nums,x) + 1;
}

int main(){
    int n;
    vector<int> nums;
    while(cin>>n){
        nums.push_back(n);
        if(cin.peek()=='\n') break;
    }

    sort(nums.begin(),nums.end());

    int x,y;
    cin>>x>>y;

    cout<<countElementsInRange(nums,x,y)<<endl;

    cin>>x>>y;

    cout<<countElementsInRange(nums,x,y)<<endl;
    return 0;
}