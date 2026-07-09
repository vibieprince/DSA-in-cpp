// int floorSqrt(int num){
//     int start = 0,end =num,mid,ans=-1;
//     while(start<end){
//         mid = start + (end-start)/2;
//         long long square = mid*mid;
//         if(square==num)
//             return mid;
//         else if(num>square){
//             ans = mid;
//             start = mid+1;
//         }
//         else
//             end = mid-1;
//     }
//     return ans;
// }
#include<iostream>
using namespace std;

double squareRoot(int n){
    if(n<0)
        return -1;
    
    double start = 0;
    double end = n;

    if(n<1)
        end = 1;

    double ans = 0;
    double epsilon = 1e-9;
    while(end-start>epsilon){
        double mid = start + (end-start)/2;
        if(mid*mid<=n){
            ans = mid;
            start = mid;
        }
        else
            end = mid;
    }
    return ans;
}

int main(){
    int n = 27;
    cout<<squareRoot(n);
    return 0;
}
