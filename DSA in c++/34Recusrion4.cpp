#include<iostream>
#include<algorithm>

using namespace std;

void reverseString(string &str,int i){
	// Base Case
	int n = str.length()-1;
	if(i>n/2)
	  return;
	
	// Processing
	swap(str[i],str[n-i]);
	i++;

	// Recursive call
	reverseString(str,i);
}
void reverseHelper(long long N, long long &ans) {
    if (N == 0)
        return;

    long long rem = N % 10;
    ans = ans * 10 + rem;
    reverseHelper(N / 10, ans);
}

long long reverse(long long N) {
    long long ans = 0;
    reverseHelper(N, ans);
    return ans;
}
void BubbleSort(int arr[],int n){
	// Base Case
	if(n<=1)
	   return;
	
	// Processing
	for(int i=0;i<n-1;i++)
	  if(arr[i]>arr[i+1])
	    swap(arr[i],arr[i+1]);
	
	// Recursive call
	BubbleSort(arr,n-1);
}
void InsertionSort(int arr[],int n){
	if(n<=1)
	  return;
	  
	InsertionSort(arr,n-1);

	int last = arr[n-1];
	int j = n-2;

	while(j>=0 && arr[j]>last){
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = last;
}
int main(){
    string str = "Prince Singh";
    long long N = 567;
    cout<<reverse(N)<<endl;
    cout<<str<<endl;
    reverseString(str,0);
    cout<<str<<endl;
	int arr[] = {4,6,6,9,5,8,53,6};
	int n = 8;
	for(int i=0;i<n;i++)
	  cout<<arr[i]<<" ";
	// BubbleSort(arr,n);
	InsertionSort(arr,n);
	cout<<endl;
	for(int i=0;i<n;i++)
	  cout<<arr[i]<<" ";

}