// Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. Return the minimum number of rooms required to attend all meetings.

// Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.

// Examples:

// Input: start[] = [1, 10, 7], end[] = [4, 15, 10]
// Output: 1
// Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings in a single room.
// Input: start[] = [2, 9, 6], end[] = [4, 12, 10]
// Output: 2
// Explanation: 1st and 2nd meetings at one room but for 3rd meeting one another room required.

#include<vector>
#include<map>
#include<iostream>
using namespace std;

int minMeetingRooms(vector<int> &start, vector<int> &end) {
    // code here
    map<int,int> timeline;
    for(int i=0;i<start.size();i++){
        timeline[start[i]]++;
        timeline[end[i]]--;
    }
    

    int minRooms = 0, room=0;
    for(auto &t : timeline){
        room += t.second;
        minRooms = max(minRooms,room);
    }
    
    return minRooms;
    
}

int main(){
    int n;
    vector<int>start(n);
    vector<int>end(n);
    for(int i=0;i<n;i++)
        cin>>start[i];
    for(int i=0;i<n;i++)
        cin>>end[i];
    cout<<minMeetingRooms(start,end);
    return 0;
}