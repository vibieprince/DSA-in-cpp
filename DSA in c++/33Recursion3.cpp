#include <iostream>
using namespace std;

bool isSorted(int arr[],int n){
    if(n==0 || n==1)
       return true;
    if(arr[0]>arr[1])
       return false;
    else 
       return isSorted(arr+1,n-1);
}

int sumArr(int arr[],int n){
    if(n==0)
      return 0;
    if(n==1)
      return arr[0];
    else  
      return arr[0] + sumArr(arr+1,n-1);
}

bool LinearSearch(int arr[],int n,int item){
    if(n==0)
      return false;
    if(arr[0]==item)
      return true;
    else
      return LinearSearch(arr+1,n-1,item);
}

bool BinarySearch(int arr[],int low,int n,int item){
  int high = n-1;
  int mid = (low+high)/2;

  // Base case
  if(low>high)
    return -1;
  
  if(arr[mid]==item)
    return 1;
  
  if(arr[mid]<item)
    return BinarySearch(arr,mid+1,n,item);
  else
    return BinarySearch(arr,low,mid-1,item);
}
int main(){
    int arr[] = {1,2,3,4,5};
    if(isSorted(arr,5))
      cout<<"Array is sorted"<<endl;
    else
      cout<<"Array is not sorted"<<endl;
    cout<<sumArr(arr,5)<<endl;
    if(LinearSearch(arr,5,0))
      cout<<"Present"<<endl;
    else
      cout<<"Absent"<<endl;
    if(BinarySearch(arr,0,5,4))
      cout<<"Present"<<endl;
    else
      cout<<"Absent"<<endl;
    return 0;
}