//  Uber   Yandex   Amazon   Google   Verkada   Facebook   DoorDash   Bloomberg 
// You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

// Return the intersection of these two interval lists.

// A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

// The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 

// Example 1:


// Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
// Example 2:

// Input: firstList = [[1,3],[5,9]], secondList = []
// Output: []

#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    int i=0,j=0;
    int n = firstList.size();
    int m = secondList.size();

    vector<vector<int>> output;
    while(i<n && j<m){
        int start = max(firstList[i][0],secondList[j][0]);
        int end = min(firstList[i][1],secondList[j][1]);
        
        if(start<=end) // overlap exitst 
            output.push_back({start,end});

        if(firstList[i][1]<secondList[j][1])
            i++;
        else
            j++;
    }
    return output;
}

int main(){
    int n,x1,x2;
    cin>>n;

    vector<vector<int>> firstList(n);
    
    for(int i=0;i<n;i++){
        cin>>x1;
        cin>>x2;
        firstList[i] = {x1,x2};
    }

    int m;
    cin>>m;

    vector<vector<int>> secondList(m);

    for(int i=0;i<m;i++){
        cin>>x1;
        cin>>x2;
        secondList[i] = {x1,x2};
    }

    vector<vector<int>> output = intervalIntersection(firstList,secondList);

    cout<<"[";
    for(vector<int> &i : output)
        cout<<"["<<i[0]<<","<<i[1]<<"]";
    cout<<"]";
}