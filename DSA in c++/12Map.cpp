// In Map data structure
// Here our data is stored in key value form
// Single key points single value
// Here also sorted
#include<iostream>
#include<map>

using namespace std;
int main(){
    map<int,string> m;
    m[1] = "Prince";
    m[13] = "King";
    m[2] = "Singh";

    m.insert({5,"Jai Bheem"});

    cout<<"Before Erase"<<endl;
    for(auto i:m)
      cout<<i.first<<" "<<i.second<<endl;

    cout<<"Finding 13 --> "<<m.count(-13)<<endl;

    // m.erase(13);
    cout<<"After erase"<<endl;
    for(auto i:m)
       cout<<i.first<<" "<<i.second<<endl;

    auto it = m.find(5);
    for(auto i=it;i!=m.end();i++)
      cout<<(*i).first<<endl;
}