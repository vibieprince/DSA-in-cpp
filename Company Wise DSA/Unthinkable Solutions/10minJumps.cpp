// class Solution {
//     int solve(int idx,int jump,vector<int>&nums){
//         if(idx>=n-1)
//             return jump;

//         int minJumps = INT_MAX;

//         for(int i=1;i<=nums[idx];i++)
//             minJumps = min(minJumps,solve(idx+i,jump+1,nums));

//         return minJumps;
//     }
// public:
//     int n;
//     int jump(vector<int>& nums) {
//         n = nums.size();
//         return solve(0,0,nums);
//     }
// };

// class Solution {
//     int n;
//     vector<int> dp;
//     int solve(int idx,vector<int>&nums){
//         if(idx>=n-1)
//             return 0;

//         if(dp[idx]!=-1)
//             return dp[idx];

//         int minJumps = INT_MAX;

//         for(int i=1;i<=nums[idx] && idx+i<n ;i++){
//             int res = solve(idx+i,nums);
//             if(res!=INT_MAX)
//                 minJumps = min(res+1,minJumps);
//         }
//         return dp[idx]=minJumps;
//     }
// public:
//     int jump(vector<int>& nums) {
//         n = nums.size();
//         dp.assign(n,-1);
//         return solve(0,nums);
//     }
// };
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0,l=0,r=0;
        while(r<nums.size()-1){
            int farthest = 0;
            for(int i=l;i<=r;i++)
                farthest = max(farthest,i+nums[i]);
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};