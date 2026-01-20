#include<iostream>
#include<vector>
using namespace std;

bool hasCycle(vector<int> &nums){
    int n = nums.size();
    if(n<=1) return false;
    int slow = 0;
    int fast = 0;

    while(true){
        if(slow < 0 || slow >= n) return false;
        if(fast < 0 || fast >= n) return false;
        if(nums[fast] < 0 || nums[fast] >= n) return false;

        slow = nums[slow];
        fast = nums[nums[fast]];

        if(slow==fast)
            return true;
    }
}
int main(){
    vector<int> nums;
    int n;
    while(cin>>n){
        nums.push_back(n);
        if(cin.peek()=='\n') break;
    }
    cout<< (hasCycle(nums) ? "Cycle exist" : "Cycle doesn't exist")<<endl;
    return 0;
}