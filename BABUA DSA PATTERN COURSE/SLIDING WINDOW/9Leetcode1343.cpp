//  LinkedIn  
// Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

 

// Example 1:

// Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
// Output: 3
// Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
// Example 2:

// Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
// Output: 6
// Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.

#include<vector>
#include<iostream>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int i=0,n=arr.size();
    int avg,count=0,sum=0;
    for(int j=0;j<n;j++){
        sum += arr[j];
        if(j-i+1==k){
            avg = sum/k;
            if(avg>=threshold) count++;
            sum -= arr[i];
            i++;
        }
    }
    return count;
}

int main(){
    vector<int> arr;
    int n;
    while(cin>>n){
        arr.push_back(n);
        if(cin.peek()=='\n') break;
    }
    int k = arr.back();
    arr.pop_back();

    int threshold = arr.back();
    arr.pop_back();
    
    cout<<numOfSubarrays(arr,k,threshold);
    return 0;
}