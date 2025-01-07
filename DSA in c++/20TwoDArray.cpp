#include<iostream>
#include<climits>
using namespace std;
bool isPresent(int arr[][4],int target,int row,int col){
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            if(arr[row][col]==target)
               return 1;
        }
    }
    return 0;
}
void sumRow(int arr[][4],int row,int col){
    for(int row=0;row<3;row++){
        int sum = 0;
        for(int col=0;col<4;col++){
            sum += arr[row][col];
        }
        cout<<sum<<endl;
    }
}
void sumColumn(int arr[][4],int row,int col){
    for(int col=0;col<4;col++){
        int sum = 0;
        for(int row=0;row<3;row++){
            sum += arr[row][col];
        }
        cout<<sum<<endl;
    }
}
void LargestRowSum(int arr[][4],int row,int col){
    int rowInd=-1,maxi = INT_MIN;
    for(int row=0;row<3;row++){
        int sum = 0;
        for(int col=0;col<4;col++){
            sum += arr[row][col];
        }
        if(sum>maxi){
           maxi = sum;
           rowInd = row;
        }
    }
    cout<<"The maximum sum is "<<maxi<<" in "<<rowInd<<" row"<<endl;
}
int main(){
    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // int arr[3][4] = {{1,4,7,10},{2,5,8,11},{3,6,9,12}};
    int arr[3][4];
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    // for(int col=0;col<4;col++){
    //     for(int row=0;row<3;row++){
    //         cout<<arr[row][col]<<" ";
    //     }
    //     cout<<endl;
    // }
    int target;
    cin>>target;

    if(isPresent(arr,target,3,4))
       cout<<"Element found"<<endl;
    else 
       cout<<"Element not found"<<endl;

    sumRow(arr,3,4);
    sumColumn(arr,3,4);
    LargestRowSum(arr,3,4);
}