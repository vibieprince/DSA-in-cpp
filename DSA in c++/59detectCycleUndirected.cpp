#include<unordered_map>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;


bool isCyclicBFS(int i,vector<bool> &visited,vector<vector<int>> &adj){
    unordered_map<int,int> parent;

    parent[i] = -1;
    visited[i] = true;

    queue<int> q;
    q.push(i);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
            else if(neighbour != parent[front])
                return true;
        }
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u = edges[i][0]-1;
        int v = edges[i][1]-1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n,false);

    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(isCyclicBFS(i,visited,adj))
                return "Yes";
        }
    }
    return "No";
}

int main(){
    int V,E;
    cin >>V>>E;

    vector<vector<int>> edges(E,vector<int> (2));

    for(int i = 0; i < E; i++)
        cin>>edges[i][0]>>edges[i][1];

    string result = cycleDetection(edges,V,E);
    
    return 0;
}