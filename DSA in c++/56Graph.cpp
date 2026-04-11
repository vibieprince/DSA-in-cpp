#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{
public:
    unordered_map<int,list<int>> adj;
    
    void addEdge(int u,int v,bool direction){
        // direction - true = directed
        // direction - false = undirected

        adj[u].push_back(v);

        if(!direction)
            adj[v].push_back(u);
    }

    void printAdjList(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second)
                cout<<j<<", ";
            cout<<endl;
        }
    }
};

int main(){
    int nodes,edges;
    cout<<"Enter the number of nodes"<<endl;
    cin>>nodes;

    cout<<"Enter the number of edges"<<endl;
    cin>>edges;

    Graph g;

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,false); // undirected graph
    }

    g.printAdjList();
    return 0;
}