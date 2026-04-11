#include<vector>
#include<iostream>
#include<queue>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int> result;
    vector<bool> visited(n,false);
    queue<int> q;

    visited[0] = true;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        result.push_back(node);

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return result;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    vector<int> ans = bfsTraversal(n,adj);

    for(int node : ans)
        cout<<node<<" ";
    
    return 0;
}