#include<iostream>
#include<vector>
using namespace std;

int recursiveLinearSearch(vector<int>&arr,int target,int i=0){
    if(i>=arr.size()) return -1;
    if(arr[i]==target) return i;
    return recursiveLinearSearch(arr,target,i+1);
}
int main(){
    vector<int> arr = {10,40,25,8,3,7,56,3,7,23,24};
    int ans = recursiveLinearSearch(arr,30);

    if(ans!=-1) cout<<"Element is present at index "<<ans;
    else cout<<"Target Element is not present in the array!"<<endl;
}