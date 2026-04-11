#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,vector<bool> &visited,vector<vector<int>> &adj, vector<int> &ans){
    ans.push_back(node);
    visited[node] = true;

    for(auto &i : adj[node]){
        if(!visited[i])
            dfs(i,visited,adj,ans);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<bool> visited(V,false);

    vector<vector<int>> result;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> ans;
            dfs(i,visited,adj,ans);
            result.push_back(ans);
        }
    }
    return result;
}

int main(){
    int V,E;
    cin >>V>>E;

    vector<vector<int>> edges(E, vector<int>(2));

    for(int i = 0; i < E; i++)
        cin>>edges[i][0]>>edges[i][1];

    vector<vector<int>> result = depthFirstSearch(V, E, edges);

    // Print connected components
    for(auto &component : result){
        for(auto &node : component){
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}