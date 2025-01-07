#include<iostream>
#include<array>

using namespace std;
int main(){
    int arr[3] = {1,2,3};
    array<int,4> a = {1,2,3,4};
    int size = a.size();

    //Traversal
    for(int i=0;i<size;i++)
        cout<<a[i]<<endl;
    
    //Direct access
    cout<<"Element at index 2 is : "<<a[2]<<endl;
    cout<<"Element at index 3 is : "<<a[3]<<endl;

    //Check if empty
    cout<<"Empty or not --> "<<a.empty()<<endl; //Return boolean

    //Find first and last element
    cout<<"First element : "<<a.front()<<endl;
    cout<<"First element : "<<a.back()<<endl;

}