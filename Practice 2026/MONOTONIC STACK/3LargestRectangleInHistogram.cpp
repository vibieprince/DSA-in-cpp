// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n, -1);
    vector<int> right(n, n);
    stack<int> s;

    // Calculate left array (forward pass: left to right)
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i])
            s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear stack for right array
    while (!s.empty()) s.pop();

    // Calculate right array (backward pass: right to left)
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i])
            s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    int area = 0;
    for (int i = 0; i < n; i++) {
        area = max(area, heights[i] * (right[i] - left[i] - 1));
    }
    return area;
}

int main(){
    vector<int> heights;
    int n;
    while(cin>>n)
        heights.push_back(n);
    int area = largestRectangleArea(heights);
    cout<<area;
}