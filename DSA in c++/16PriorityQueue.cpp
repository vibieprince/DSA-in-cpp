#include<iostream>
#include<queue>

using namespace std;
int main(){

    // Max Heap
    priority_queue<int> maxi;

    // Min Heap
    priority_queue<int,vector<int>,greater<int>> mini;

    // Maxi
    maxi.push(1);
    maxi.push(5);
    maxi.push(12);
    maxi.push(10);

    cout<<"Maxi : ";

    int n = maxi.size();
    for(int i=0;i<n;i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;

    // Mini
    mini.push(5);
    mini.push(1);
    mini.push(12);
    mini.push(10);

    cout<<"Mini : ";

    int m = mini.size();
    for(int i=0;i<m;i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;

    cout<<"Khali hai kya ?? --> "<<maxi.empty()<<endl;
    cout<<"Khali hai kya ?? --> "<<mini.empty()<<endl;
}