// Problem Statement : Given an arraylist of 'arr' integers and a position 'm'. You have to reverse the array after that position.
#include<bits/stdc++.h>
using namespace std;
void reverseArray(vector<int> &arr,int m){
    int start = m+1,end=arr.size()-1;
    while(start!=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
int main(){
    vector<int> v = {4,5,7,2,5};
    reverseArray(v,1);
    for(int i:v)
      cout<<i<<endl;
}