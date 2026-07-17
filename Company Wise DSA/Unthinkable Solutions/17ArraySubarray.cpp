// You are given an array, You have to choose a contiguous subarray of length ‘k’, and find the minimum of that segment, return the maximum of those minimums.
// Sample input :
// 1 → Length of segment x =1
// 5 → size of space n = 5
// 1 → space = [ 1,2,3,1,2]
// 2
// 3
// 1
// 2

// Sample output :
// 3
// Explanation :
// The subarrays of size x = 1 are [1],[2],[3],[1], and [2],Because each subarray only contains 1 element, each value is minimal with respect to the subarray it is in. The maximum of these values is 3. Therefore, the answer is 3

#include<iostream>
#include<deque>
#include<climits>
using namespace std;

int main(){
    int l,s;
    cin>>l>>s;

    int ans = INT_MIN;

    int arr[s];
    for(int i=0;i<s;i++)
        cin>>arr[i];

    deque<int> dq;

    for(int i=0;i<s;i++){
        while(!dq.empty() && dq.front()>=i-l)
            dq.pop_front();
        
        while(!dq.empty() && arr[dq.back()] >= arr[i])
            dq.pop_back();
        
        dq.push_back(i);

        if(i >= l-1)
            ans = max(ans,arr[dq.front()]);
    }

    cout<<ans;
}