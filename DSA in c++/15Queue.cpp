#include<iostream>
#include<queue>
// Queue --> first in first out [FOFO]
using namespace std;

int main(){
    queue<string> q;

    q.push("Prince");
    q.push("Singh");

    cout<<"Size before pop : "<<q.size()<<endl;
    cout<<"First Element : "<<q.front()<<endl;

    q.pop();

    cout<<"First element : "<<q.front()<<endl;
    cout<<"Size after pop : "<<q.size()<<endl;

}