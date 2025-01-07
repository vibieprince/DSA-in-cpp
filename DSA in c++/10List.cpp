#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;
    
    l.push_back(5);
    l.push_front(6);
    
    list<int> newlist(l);
    for(int i:newlist)
      cout<<i<<endl;
    

    for(int i:l)
      cout<<i<<endl;

    l.erase(l.begin());
    cout<<"After Erase : ";
    for(int i:l)
      cout<<i<<endl;

    cout<<"Size of list : "<<l.size()<<endl;
}