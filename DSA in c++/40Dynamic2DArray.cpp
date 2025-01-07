#include<iostream>
using namespace std;
int main(){
    // int n;
    int row;
    int col;
    cin>>row>>col;
    
    // Initialise 2D array by DMA
    int **arr = new int *[row];   

    for(int i=0;i<row;i++){
        arr[i] = new int[col];
    }
    // Creation Done

    // Taking inputs
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }

    // Output
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<" "<<arr[i][j];
        }
        cout<<endl;
    }

    // Free Memory
    for(int i=0;i<row;i++)
       delete[]arr[i];
    
    delete[]arr;
    return 0;
}