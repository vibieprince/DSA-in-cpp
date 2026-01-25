//  Amazon  
// Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

// The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

// Return the number of remaining intervals.

 

// Example 1:

// Input: intervals = [[1,4],[3,6],[2,8]]
// Output: 2
// Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
// Example 2:

// Input: intervals = [[1,4],[2,3]]
// Output: 1

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Appraoch 1
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int count = 0;
    for(int i=0;i<intervals.size();i++){
        int c = intervals[i][0];
        int d = intervals[i][1];
        bool isCovered = false;
        for(int j=0;j<intervals.size();j++){
            int a = intervals[j][0];
            int b = intervals[j][1];

            if(i != j && (a<=c && b >= d)){
                isCovered = true;
                break;
            }
        }
        if(!isCovered) count++;
    }
    return count;
}

// Appraoch 2
static bool comparator(vector<int>a,vector<int> b){
    if(a[0]==b[0])
        return a[1] > b[1];
    return a[0]<b[0];
}
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int count = 0;
    int maxEnd = 0;
    sort(intervals.begin(),intervals.end(),comparator);
    for(vector<int> &i : intervals){
        if(i[1]>maxEnd){
            count++;
            maxEnd = i[1];
        }
    }
    return count;
}

int main(){
    int n,x1,x2;
    cin>>n;

    vector<vector<int>> intervals(n);
    for(int i=0;i<n;i++){
        cin>>x1>>x2;
        intervals[i] = {x1,x2};
    }

    cout<<removeCoveredIntervals(intervals);
    return 0;
}