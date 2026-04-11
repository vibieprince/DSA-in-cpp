#include<iostream>
using namespace std;
#include<vector>
#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++)
        adj[edges[i][0]].push_back(edges[i][1]);
    
    vector<int> indegree(v);
    for(int i=0;i<v;i++){
        for(auto &neighbour : adj[i])
            indegree[neighbour]++;
    }

    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto &neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
                q.push(neighbour);
        }
    }
    return ans;
}

int main(){
    int v,e;
    cin>>v>>e;

    vector<vector<int>> edges(e,vector<int>(2));
    for(int i=0;i<e;i++)
        cin>>edges[i][0]>>edges[i][1];

    vector<int> ans = topologicalSort(edges,v,e);
    for(int &i : ans)
        cout<<i<<" ";
    return 0;
}