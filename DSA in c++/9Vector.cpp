#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main(){
    vector<int> v;
    // cout<<"Capacity --> "<<v.capacity()<<endl;

    //If size already known
    vector<int> a(5,1);
    for(int i:a)
      cout<<i<<endl;
    
    // Copying another vector into other
    vector<int> last(a);
    for(int i:last)
      cout<<i<<endl;
    v.push_back(1);
    // cout<<"Capacity --> "<<v.capacity()<<endl;

    v.push_back(2);
    // cout<<"Capacity --> "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity --> "<<v.capacity()<<endl;

    cout<<"Size --> "<<v.size()<<endl;

    // cout<<"Element at index 2 : "<<v[2]<<endl;
    cout<<"Element at index 2 : "<<v.at(2)<<endl;
    
    cout<<"Front : "<<v.front()<<endl;
    cout<<"Back : "<<v.back()<<endl;

    cout<<"Before pop"<<endl;
    // for(int i=0;i<v.size();i++)
    for(int i:v)
      cout<<i<<endl;

    v.pop_back();

    cout<<"After pop"<<endl;
    // for(int i=0;i<v.size();i++)
    for(int i:v)
      cout<<i<<endl;

    cout<<"Before clear size : "<<v.size()<<endl;
    v.clear();
    cout<<"After clear size : "<<v.size()<<endl;
}