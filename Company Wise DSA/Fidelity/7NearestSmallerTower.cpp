// Given an array representing the heights of towers, the task is to find, for each tower, the index of the nearest tower that is shorter than it.
// The search for a shorter tower can be performed by looking to the left and right sides of each tower.

// The following rules apply:

// If there are two or more smaller towers at the same distance from the current tower, choose the tower with the smallest height.
// If two towers have the same height, choose the one with the smaller index.
// Example 1:

// Input : Array: [1, 3, 2]
// Output : Indexes: [-1, 0, 0]
// Explanation:
// For the tower at index 0, there is no tower shorter than it, so the output is -1.

// For the tower at index 1 (height 3), there are two towers (heights 1 and 2) at the same distance. Following the rules, we choose the tower with the smallest height, which is at index 0.
// For the tower at index 2 (height 2), the only tower shorter than it is at index 0.
// Therefore, the final output is the array of indexes: [-1, 0, 0].

// Example 2:
//                  0  1  2  3  4
// Input : Array : [4, 8, 3, 5, 3]
// Output : Indexes: [2, 2, -1, 2, -1]
// Explanation:

// For the tower at index 0 (height 4), the nearest tower shorter than it is at index 2.
// For the tower at index 1 (height 8), there are two towers (heights 4 and 3) at the same distance.
// Following the rules, we choose the tower at index 2.
// For the tower at index 2 (height 3), there is no tower shorter than it.
// For the tower at index 3 (height 5), there are two towers (heights 3 and 3) at the same distance.
// Following the rules, we choose the tower at index 2 because it has a smaller index.
// For the tower at index 4 (height 3), there is no tower shorter than it.
// Therefore, the final output is the array of indexes: [2, 2, -1, 2, -1].

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> nums;
    int x;
    while (cin >> x) {
        nums.push_back(x);
        if (cin.peek() == '\n') break;
    }

    int n = nums.size();
    vector<int> NSL(n, -1), NSR(n, -1);

    // -------- NSL (Nearest Smaller to Left) --------
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

        if (!st.empty())
            NSL[i] = st.top();

        st.push(i);
    }

    // Clear stack
    while (!st.empty()) st.pop();

    // -------- NSR (Nearest Smaller to Right) --------
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

        if (!st.empty())
            NSR[i] = st.top();

        st.push(i);
    }

    // -------- Final result logic --------
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        if (NSL[i] == -1 && NSR[i] == -1)
            result[i] = -1;
        else if (NSL[i] == -1)
            result[i] = NSR[i];
        else if (NSR[i] == -1)
            result[i] = NSL[i];
        else {
            int distL = abs(i - NSL[i]);
            int distR = abs(i - NSR[i]);

            if (distL < distR)
                result[i] = NSL[i];
            else if (distR < distL)
                result[i] = NSR[i];
            else {
                if (nums[NSL[i]] < nums[NSR[i]])
                    result[i] = NSL[i];
                else if (nums[NSR[i]] < nums[NSL[i]])
                    result[i] = NSR[i];
                else
                    result[i] = min(NSL[i], NSR[i]);
            }
        }
    }

    // Print result
    for (int i : result)
        cout << i << " ";

    return 0;
}
