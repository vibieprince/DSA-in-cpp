#include<iostream>
using namespace std;
void merge(int *arr,int low,int high){
    int mid = (low+high)/2;

    int len1 = mid - low + 1;
    int len2 = high - mid;

    int *first = new int[len1];
    int *second = new int[len2];
    
    // Copy Values
    int k = low;
    for(int i=0;i<len1;i++)
        first[i] = arr[k++];
    k = mid+1;           // k shows your main array index
    for(int i=0;i<len2;i++)
       second[i] = arr[k++];

    int index1 = 0;
    int index2 = 0;
    k = low;
    while(index1 < len1 && index2 <len2){
        if(first[index1]<second[index2])
           arr[k++] = first[index1++];
        else
           arr[k++] = second[index2++];
    }
    while(index1<len1)
       arr[k++] = first[index1++];
    while(index2<len2)
       arr[k++] = second[index2++];
    delete []first;
    delete []second;
}
void mergeSort(int *arr,int low,int high){
    // Base Case
    if(low>=high)
       return;

    int mid = (low+high)/2;
    
    // Left part Sort
    mergeSort(arr,low,mid);

    // Right part Sort
    mergeSort(arr,mid+1,high);

    merge(arr,low,high);
}
int main(){
    int arr[] = {2,5,1,6,9};
    int n = 5;
    // for(int i=0;i<n;i++)
    //   cout<<arr[i]<<" ";
    // cout<<endl;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    return 0;
}