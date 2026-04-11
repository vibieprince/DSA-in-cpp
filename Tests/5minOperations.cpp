#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_set>
#include<climits>
#include<unordered_map>
using namespace std;

int operations(int n,int m){
    if(n>m)
        return (m-n);

    queue<pair<int,int>> q;
    q.push({n,0});

    while(!q.empty()){
        pair<int,int> front = q.front();
        int Node = front.first;
        int step = front.second;

        if(Node==m)
            return step;
        
        q.push({Node*2,step+1});
        q.push({Node-1,step+1});
    }
}

vector<int> CommonElements(vector<int> arr1,vector<int> arr2,vector<int> arr3){
    unordered_map<int,int> mp;
    vector<int> ans;

    unordered_set<int> s1(arr1.begin(),arr1.end());
    unordered_set<int> s2(arr2.begin(),arr2.end());
    unordered_set<int> s3(arr3.begin(),arr3.end());

    for(int x : s1)
        mp[x]++;

    for(int x : s2)
        mp[x]++;

    for(int x : s3)
        mp[x]++;

    for(auto &it : mp)
        if(it.second == 3)
            ans.push_back(it.first);

    return ans;
}
int main(){
    vector<int> arr1 = {1,5,11,3,8};
    vector<int> arr2 = {1,9,3,4};
    vector<int> arr3 = {2,2,1,2,3};
    vector<int> result = CommonElements(arr1,arr2,arr3);
    cout<<result[0]<<" "<<result[1];

    return 0;
}

