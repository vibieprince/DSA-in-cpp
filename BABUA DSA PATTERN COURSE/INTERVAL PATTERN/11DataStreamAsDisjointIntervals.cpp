//  Microsoft  

// Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

// Implement the SummaryRanges class:

// SummaryRanges() Initializes the object with an empty stream.
// void addNum(int value) Adds the integer value to the stream.
// int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.
 

// Example 1:

// Input
// ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
// [[], [1], [], [3], [], [7], [], [2], [], [6], []]
// Output
// [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

// Explanation
// SummaryRanges summaryRanges = new SummaryRanges();
// summaryRanges.addNum(1);      // arr = [1]
// summaryRanges.getIntervals(); // return [[1, 1]]
// summaryRanges.addNum(3);      // arr = [1, 3]
// summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
// summaryRanges.addNum(7);      // arr = [1, 3, 7]
// summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
// summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
// summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
// summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
// summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
#include<iostream>
#include<vector>
#include<set>
using namespace std;
class SummaryRanges {
public:
    set<int> arr;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        arr.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        int left=-1,right=-1;
        vector<vector<int>> result;
        for(int num : arr){
            if(left==-1 && right==-1){
                left = num;
                right = num;
            }
            else if(num==right+1)
                right = num;
            else{
                result.push_back({left,right});
                left = num;
                right = num;
            }
        }
        if(left!=-1)
            result.push_back({left,right});
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

int main(){
    int n;
    cout << "Enter number of operations: ";
    cin >> n;
    
    SummaryRanges* obj = new SummaryRanges();
    
    for(int i = 0; i < n; i++){
        int operation;
        cout << "\nOperation " << i+1 << ":\n";
        cout << "1. addNum\n2. getIntervals\nChoose: ";
        cin >> operation;
        
        if(operation == 1){
            int value;
            cout << "Enter value: ";
            cin >> value;
            obj->addNum(value);
            cout << "Value " << value << " added successfully";
        }
        else if(operation == 2){
            vector<vector<int>> intervals = obj->getIntervals();
            cout << "Intervals: ";
            if(intervals.empty()){
                cout << "[]";
            }
            else{
                cout << "[";
                for(int j = 0; j < intervals.size(); j++){
                    cout << "[" << intervals[j][0] << "," << intervals[j][1] << "]";
                    if(j < intervals.size()-1) cout << ",";
                }
                cout << "]";
            }
        }
        else{
            cout << "Invalid operation!";
        }
    }
    
    delete obj;
    return 0;
}

