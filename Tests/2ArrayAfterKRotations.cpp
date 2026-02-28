// You are given an array of N integers and an integer K.

// Your task is to print the array after performing K rotations.

// Since K can be larger than N, you must handle large values efficiently.

// 🔁 What is Rotation?

// There are usually two types:

// 1️⃣ Right Rotation

// Each rotation moves the last element to the front.

// Example:

// Array: 1 2 3 4 5
// After 1 right rotation:
// 5 1 2 3 4
// 2️⃣ Left Rotation

// Each rotation moves the first element to the end.

// Example:

// Array: 1 2 3 4 5
// After 1 left rotation:
// 2 3 4 5 1

// Here you’ll assume Right Rotation (most common version).
// First line: Integer N

// Second line: N space-separated integers

// Third line: Integer K

// 📤 Output Format

// Print the array after K right rotations.

// 📌 Constraints

// 1 ≤ N ≤ 10^5

// 0 ≤ K ≤ 10^18

// -10^9 ≤ Ai ≤ 10^9
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int k;
    cin>>k;
    
    k = k %n;

    for(int i=n-k;i<n;i++)
        cout<<arr[i]<<" ";
    
    for(int i=0;i<n-k;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}