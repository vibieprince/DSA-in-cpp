#include <iostream>
using namespace std;

int main(){
    int row,col;
    row = 3;

    int **arr = new int*[row];
    int sizes[] = {4,2,3}; // Columns for respective row

    for(int i=0;i<row;i++)
      *(arr+i) = new int[sizes[i]]; // Creating column of sizes[i] for each row
    
    // Input from user
    for(int i=0;i<row;i++){
        for(int j=0;j<sizes[i];j++){
            cout<<"Enter element "<<i<<" "<<j<<" : "<<endl;
            cin>>arr[i][j];
        }
    }

    cout<<"Jagged matrix"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<sizes[i];j++)
          cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    // Free Memory
    for(int i=0;i<row;i++)
       delete[] arr[i];
    
    delete[]arr;

    return 0;
}