#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // write you code here
    vector<vector<int>> adj(n);
    for(auto &i : edges)
        adj[i.first-1].push_back(i.second-1);
    
    vector<int> indegree(n);
    for(int i=0;i<n;i++){
        for(auto &neighbour : adj[i])
            indegree[neighbour]++;
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    int count = 0;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        count++;

        for(auto &neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
                q.push(neighbour);
        }
    }

    return count != n;
}

int main(){
     int V,E;
    cin >>V>>E;

    vector<pair<int,int>> edges(E);

    for(int i = 0; i < E; i++)
        cin>>edges[i].first>>edges[i].second;

    bool result = detectCycleInDirectedGraph(V,edges);
    
    return 0;
}