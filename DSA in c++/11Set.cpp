#include<iostream>
using namespace std;

// Only unique elements
// No modifications
// Else delete or keep
// Returns the element in sorted order

// Set is quite slower than unordered set

#include<set>
int main(){
    set<int> s;

    s.insert(5);
    s.insert(6);
    s.insert(1);
    s.insert(5);
    s.insert(5);
    s.insert(1);

    // for(auto i:s)
    for(int i:s)
      cout<<i<<endl;

    s.erase(s.begin()); // 1 deleted here

    set<int>::iterator it = s.begin(); // now begin is 5
    it++; // 5 --> 6

    s.erase(it); // 6 deleted here 

    for(auto i:s)
      cout<<i<<endl; // 5 prints only
    
    cout<<endl;
    cout<<"(5) Present or not : "<<s.count(5)<<endl;
    cout<<"(-5) Present or not : "<<s.count(-5)<<endl;
    cout<<"(6) Present or not : "<<s.count(6)<<endl;

    set<int>::iterator itr = s.find(5);

    for(auto i=itr;i!=s.end();i++)
      cout<<*i<<" "; // prints find element its aage ke
    cout<<endl;
}