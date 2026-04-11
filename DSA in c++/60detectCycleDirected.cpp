#include<vector>
#include<iostream>
using namespace std;

bool checkCycleDFS(int i,vector<bool> &visited,vector<bool>& dfsVisited,vector<vector<int>> &adj){
  visited[i] = true;
  dfsVisited[i] = true; 

  for(auto &neighbour : adj[i]){
    if(!visited[neighbour]){
      bool cycleFound = checkCycleDFS(neighbour,visited,dfsVisited,adj);
      if(cycleFound)
        return true;
    }
    else if(dfsVisited[neighbour])
      return true;
  }
  dfsVisited[i] = false;
  return false;
}

bool detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<vector<int>> adj(n+1);
  for(auto &i : edges)
    adj[i.first].push_back(i.second);

  vector<bool> visited(n+1,false);
  vector<bool> dfsVisited(n+1,false);

  for(int i=1;i<=n;i++){
    if(!visited[i]){
      bool cycleFound = checkCycleDFS(i,visited,dfsVisited,adj);
      if(cycleFound)
        return true;
    }
  }
  return false;
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