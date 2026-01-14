// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.


// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int,int>> s;
    int n = temperatures.size();
    vector<int> ans(n,0);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top().first <=temperatures[i])
            s.pop();
        if(!s.empty())
            ans[i] = s.top().second - i;
        s.push({temperatures[i],i});
    }
    return ans;
}

int main(){
    vector<int> temperatures;
    int n;
    while(cin>>n)
        temperatures.push_back(n);
    temperatures = dailyTemperatures(temperatures);
}

