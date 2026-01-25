//  Google   Amazon  

// A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)

// You are given some events [startTime, endTime), after each given event, return an integer k representing the maximum k-booking between all the previous events.

// Implement the MyCalendarThree class:

// MyCalendarThree() Initializes the object.
// int book(int startTime, int endTime) Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.
 

// Example 1:

// Input
// ["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
// [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
// Output
// [null, 1, 1, 2, 3, 3, 3]

// Explanation
// MyCalendarThree myCalendarThree = new MyCalendarThree();
// myCalendarThree.book(10, 20); // return 1
// myCalendarThree.book(50, 60); // return 1
// myCalendarThree.book(10, 40); // return 2
// myCalendarThree.book(5, 15); // return 3
// myCalendarThree.book(5, 10); // return 3
// myCalendarThree.book(25, 55); // return 3
#include<map>
#include<iostream>
using namespace std;

class MyCalendarThree {
public:
    map<int,int> timeline;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        timeline[startTime]++;
        timeline[endTime]--;

        int maxk = 0,k=0;
        for(auto &t : timeline){
            k += t.second;
            maxk = max(maxk,k);
        }
        return maxk;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
int main(){
    MyCalendarThree* obj = new MyCalendarThree();
    int n;
    cin>>n;
    while(n--){
        int x1,x2;
        cin>>x1>>x2;
        cout<<obj->book(x1,x2);
    }
    return 0;
}