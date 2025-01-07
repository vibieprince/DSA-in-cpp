#include<iostream>
using namespace std;
void update(int *p){
    *p = (*p) * 2;
}
void fun(int arr[]){
    cout<<arr[0]<<" ";
}
void increment(int **p){
    ++(**p);
}
int main(){
    // 1
    // int first = 8;
    // int second = 18;
    // int *ptr = &second;
    // *ptr = 9;
    // cout<<first<<" "<<second<<endl; // 8 9 

    // 2
    // int first = 6;
    // int *p = &first;
    // int *q = p;
    // (*q)++;
    // cout<<first<<endl; // 7

    // 3
    // int first = 8;
    // int *p = &first;
    // cout<<(*p)++<<" "; // 8
    // cout<<first<<endl; // 9

    // 4
    // int *p = 0;
    // int first = 110;
    // // *p = first; // segmentation fault
    // p = &first;
    // cout<<*p<<endl; //110

    // 5
    // int first = 8;
    // int second = 11;
    // int *third = &second;
    // first = *third;
    // *third = *third + 2;
    // cout<<first<<" "<<second<<endl; // 11 13

    // 6 
    // float f = 12.5;
    // float p = 21.5;
    // float *ptr = &f;
    // (*ptr)++;
    // *ptr = p;
    // cout<<*ptr<<" "<<f<<" "<<p<<endl; // 21.5 21.5 21.5

    // 7 
    // int arr[5];
    // int *ptr;
    // cout<<sizeof(arr)<<" "<<sizeof(ptr)<<endl; // 20 4

    // 8
    // int arr[] = {11,21,13,14};
    // cout<<*(arr)<<" "<<*(arr+1)<<endl; // 11 21

    // 9 
    // int arr[6] = {11,12,13};
    // cout<<arr<<" "<<&arr<<endl;  // address of 0th index element

    // 10 
    // int arr[6] = {11,21,13};
    // cout<<(arr+1)<<endl; // address of 1st index element

    // 11 
    // int arr[6] = {11,21,13};
    // int *p = arr;
    // cout<<p[2]<<endl; *(p+2);

    // 12
    // int arr[] = {11,12,13,14,15};
    // cout<<*(arr)<<" "<<*(arr+3); // 13

    // 13
    // int arr[] = {11,21,31,41};
    // // int *ptr = arr++; // Erro ---> No possible updates in symbol table 
    // cout<<*ptr<<endl;

    // 14
    // char ch = 'a';
    // char *ptr = &ch;
    // ch++;
    // cout<<*ptr<<endl; //b

    // 15
    // char arr[] = "abcde";
    // char *p = &arr[0];
    // cout<<p<<endl; //abcde

    // 16 
    // char arr[] = "abcde";
    // char *p = &arr[0];
    // p++;
    // cout<<p<<endl; //bcde

    // 17 
    // char str[] = "Singh";
    // char *p = str;
    // cout<<str[0]<<" "<<p[0]<<endl; // S S

    // 18 
    // int i = 10;
    // update(&i);
    // cout<<i<<endl; //20

    // 19
    // int arr[] = {11,12,13,14};
    // fun(arr+1); // 12
    // cout<<arr[0]<<endl; // 11

    // 20 
    // int first = 110;
    // int *p = &first;
    // int **q = &p;
    // int second = (**q)++ + 9;
    // cout<<first<<" "<<second<<endl; //111 119

    // 21 
    // int first = 100;
    // int *p = &first;
    // int **q = &p;
    // int second = ++(**q);
    // int *r = *q;
    // ++(*r);
    // cout<<first<<" "<<second<<endl; // 102 101

    // 22
    // int num = 110;
    // int *ptr = &num;
    // increment(&ptr);
    // cout<<num<<endl; //111
    
    return 0;
}