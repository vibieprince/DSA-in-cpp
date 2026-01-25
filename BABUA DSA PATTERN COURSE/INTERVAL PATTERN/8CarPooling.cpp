//  Amazon   Google   DoorDash   Flipkart   Facebook   Microsoft   Bloomberg   Cruise Automation  
// There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

// You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

// Example 1:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false
// Example 2:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
// Output: true

#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    map<int,int> timeline;
    for(auto &t : trips){
        timeline[t[1]] += t[0];
        timeline[t[2]] -= t[0];
    }
    int cap = 0;
    for(auto &t : timeline){
        cap += t.second;
        if(cap > capacity)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> trips;
    while(n--){
        int x1,x2;
        cin>>x1>>x2;
        trips.push_back({x1,x2});
    }

    int capacity;
    cin>>capacity;

    cout<<(carPooling(trips,capacity)?"true":"false");
    return 0;
}