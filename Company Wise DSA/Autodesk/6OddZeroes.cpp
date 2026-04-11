#include<iostream>
#include<vector>
using namespace std;

int ZeroesCount(int num){
    int count = 0;
    if(num==0) count = 1;
    while(num){
        int rem = num%10;
        if(rem==0) count++;
        num /= 10;
    }
    return count;
}

vector<int> oddCountZeroes(vector<int> nums){
    vector<int> result;
    for(int i : nums){
        if(ZeroesCount(i)%2!=0)
            result.push_back(i);
    }
    return result;
}
