//  IBM   Uber   Apple   Adobe   Cisco   GEICO   Amazon   Google   VMware   Oracle   Yandex   Shopee   Intuit   Nvidia   tiktok   Twitter   Facebook   LinkedIn   Snapchat   Bloomberg   Microsoft   ByteDance   Salesforce   Morgan Stanley   Walmart Global Tech  

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// Example 3:

// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]
// Explanation: Intervals [1,4] and [4,7] are considered overlapping.

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> result = {{intervals[0][0],intervals[0][1]}};
    for(int i=1;i<intervals.size();i++){
        if(result.back()[1] >= intervals[i][0])
            result.back()[1] = max(result.back()[1],intervals[i][1]);
        else
            result.push_back(intervals[i]);   
    }
    return result;
}

int main() {
    // Example 1
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result1 = merge(intervals1);
    cout << "Example 1: ";
    for(auto interval : result1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << "\n";
    
    // Example 2
    vector<vector<int>> intervals2 = {{1,4},{4,5}};
    vector<vector<int>> result2 = merge(intervals2);
    cout << "Example 2: ";
    for(auto interval : result2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << "\n";
    
    // Example 3
    vector<vector<int>> intervals3 = {{4,7},{1,4}};
    vector<vector<int>> result3 = merge(intervals3);
    cout << "Example 3: ";
    for(auto interval : result3) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << "\n";
    
    return 0;
}

