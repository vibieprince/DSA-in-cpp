// Problem statement : given vector A = {3,4,5} & B = {7,6,1}
// give the resultant vector ans = {1,1,0,6}

#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
vector<int>findArraySum(vector<int>&A,int n,vector<int>&B,int m){
    int i = n-1;
    int j = m-1;
    int carry = 0;
    vector<int>ans;
    while(i>=0 && j>=0){
        int sum = A[i] + B[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while(i>=0){
        int sum = A[i]+carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    while(j>=0){
        int sum = B[i]+carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }
    while(carry!=0){
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for(int i:ans)
       cout<<i<<" ";
}
int main(){
    vector<int> A = {3,4,5};
    vector<int> B = {7,6,1};
    int n=A.size();
    int m=B.size();
    findArraySum(A,n,B,m);
}