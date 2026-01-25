//  Google   Amazon   LinkedIn   Facebook   Robinhood  
// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

// Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if(intervals.empty()) return {newInterval};

    vector<vector<int>> output;
    int i=0,n=intervals.size();

    while(i<n && intervals[i][1]<newInterval[0]){
        output.push_back(intervals[i]);
        i++;
    }

    while(i<n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0],intervals[i][0]);
        newInterval[1] = max(newInterval[1],intervals[i][1]);
        i++;
    }

    output.push_back(newInterval);

    while(i<n)
        output.push_back(intervals[i++]);
    
    return output;
}
int main(){
    int n,x1,x2;
    cin>>n;

    vector<vector<int>> intervals(n);
    
    for(int i=0;i<n;i++){
        cin>>x1;
        cin>>x2;
        intervals[i] = {x1,x2};
    }

    vector<int> newInterval(2);

    for(int i=0;i<2;i++){
        cin>>x1;
        newInterval[i] = x1;
    }   

    vector<vector<int>> output = insert(intervals,newInterval);

    cout<<"[";
    for(vector<int> &i : output)
        cout<<"["<<i[0]<<","<<i[1]<<"]";
    cout<<"]";
}