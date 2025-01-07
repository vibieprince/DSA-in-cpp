#include<iostream>
using namespace std;
int main(){
    int arr[10] = {23,122,41,67};
    // cout<<"Address of first memory block is "<<arr<<endl; //OR 
    cout<<"Address of first memory block is "<<&arr[0]<<endl;

    cout<<"4th "<<*arr<<endl; // 23
    cout<<"5th "<<*arr + 1<<endl; // 24
    cout<<"6th "<<*(arr + 1)<<endl; // 122
    cout<<"7th "<<*(arr) + 1<<endl; // 24
    cout<<"8th "<<arr[2]<<endl; // 41
    cout<<"9th "<<*(arr+2)<<endl; // 41

    // arr[i] = *(arr+i)
    // i[arr] = *(i+arr) //--> No Error

    int i = 3;
    cout<<i[arr]<<endl; // 67

    int temp[10] = {1,2,3};
    cout<<sizeof(temp)<<endl; //40
    cout<<"1st "<<sizeof(*temp)<<endl; //4
    cout<<"2nd "<<sizeof(&temp)<<endl; //4

    int *ptr = &temp[0]; 
    cout<<sizeof(ptr)<<endl; //4
    cout<<sizeof(*ptr)<<endl; //4

    int a[20] = {1,2,34,5};
    cout<<&a[0]<<endl; 
    cout<<&a<<endl;
    cout<<a<<endl;

    int *q = &a[0];
    cout<<q<<endl;
    cout<<*q<<endl; //1
    cout<<&q<<endl; 

    int array[10] = {1,2};
    // array = array + 1; //--> Error
    int *pt = &array[0];
    pt = pt + 1;
    cout<<pt<<endl;
    cout<<*pt<<endl; //2
    return 0;
}