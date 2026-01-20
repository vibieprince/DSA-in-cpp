// You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

// Define a pair (u, v) which consists of one element from the first array and one element from the second array.

// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

// Example 1:

// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return (a.first+a.second) < (b.first + b.second); // max-heap creation
    }
};

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;

    for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            int sum = nums1[i] + nums2[j];
            if(pq.size()<k)
                pq.push({nums1[i],nums2[j]});
            else if(pq.top().first+pq.top().second > sum){
                pq.pop();
                pq.push({nums1[i],nums2[j]});
            }
            else if(pq.size() == k) {
                break; // 🔥 PRUNING
            }
        }
    }

    vector<vector<int>> ans;
    while(!pq.empty()){
        ans.push_back({pq.top().first,pq.top().second});
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int> nums1;
    vector<int> nums2;

    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        nums1.push_back(x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        nums2.push_back(x);
    }
    int k;
    cin>>k;
    vector<vector<int>> ans = kSmallestPairs(nums1,nums2,k);
    cout<<"[";
    for(vector<int> &i : ans)
        cout<<"["<<i[0]<<","<<i[1]<<"]";
    cout<<"]";
}