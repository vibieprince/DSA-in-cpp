#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(7);
    v.push_back(4);
    v.push_back(3);
    v.push_back(9);

    // cout<<"Finding 6 : "<<binary_search(v.begin(),v.end(),6)<<endl;
    cout<<"Finding 7 : "<<binary_search(v.begin(),v.end(),7)<<endl;

    cout<<"Lower bound ---> "<<lower_bound(v.begin(),v.end(),3)-v.begin()<<endl;
    cout<<"Upper bound ---> "<<upper_bound(v.begin(),v.end(),3)-v.begin()<<endl;

    int a = 3;
    int b = 5;
    cout<<"Max --> "<<max(a,b)<<endl;
    cout<<"Min --> "<<min(a,b)<<endl;
    swap(a,b);
    cout<<"a : "<<a<<endl<<"b : "<<b<<endl;

    string s = "abcd";
    reverse(s.begin(),s.end());
    cout<<"String --> "<<s<<endl;

    cout<<"Before rotation"<<endl;
    for(int i:v)
      cout<<i<<" ";
    rotate(v.end(),v.end()-1,v.begin());
    cout<<"After Rotation"<<endl;
    for(int i:v)
      cout<<i<<" ";

    sort(v.begin(),v.end());
    cout<<endl;
    for(int i:v)
      cout<<i<<" ";
}