// Mr X is a teacher of maths. He came across a very simple problem. In the problem you have to arrange the numbers in an ascending order and calculate the total number of swaps required. The number of swaps must be minimum. But Mr X is busy with some other tasks and you being his favourite student , so he asks you to solve this problem.

// Constraints:
// 1<=T<=100
// 1<=N<=100
// 1<=A[ ] <=1000
// Examples

// Input :
// 4
// 4 3 1 2
// Output:
// 2
// Explanation: Swap index 0 with 3 and 1 with 2 to form the sorted array {1, 2, 3, 4}.

// Input :
// 5
// 1 5 4 3 2
// Output :
// 2
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector < int > arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector < pair < int, int >> ap(n);
    for (int i = 0; i < n; i++) {
        ap[i].first = arr[i];
        ap[i].second = i;
    }
    sort(ap.begin(), ap.end());
	int swapCount = 0;
    for(int i=0;i<n;i++){
		if(ap[i].second==i) continue;
		swapCount++;
		swap(ap[i],ap[ap[i].second]);
		--i;
	}
    cout << swapCount;
    return 0;
}