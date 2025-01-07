// Problem Statement : For a given two-dimensional arraylist 'ARR' of size (NxM),print the 'ARR' in a sine wave order,i.e., print the first column top to bottom,next column bottom to top, and so on.
// For eg. 
// The sine wave for the matrix:-
// 1 2
// 3 4
// will be {1,3,4,2}.
#include<iostream>
#include<vector>
using namespace std;
void wavePrint(int arr[][4],int row,int col){
    vector<int> result;
    for(int j=0;j<col;j++){
        if(j%2==0){
            for(int i=0;i<row;i++)
               result.push_back(arr[i][j]);
        }
        else{
            for(int i=row-1;i>=0;i--)
               result.push_back(arr[i][j]);
        }
    }
    for(int i : result)
      cout<<i<<" ";
}
int main(){
    int arr[3][4] = {{1,2,5,6},{3,6,7,4},{6,7,8,9}};
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    wavePrint(arr,3,4);
    return 0;
}