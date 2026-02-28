// Sita and Geeta are playing a game based on bit manipulation.
// They are given an array of N positive integers. The game is played as follows:
// Sita always plays first.
// Players take turns alternately.
// In one move, a player can choose any number from the array and change it to any smaller non-negative integer.
// The player who makes the last valid move wins.
// Both Sita and Geeta play optimally.
// Your task is to determine whether Sita will win the game or not.
// 🧠 Important Insight

// This problem follows the Nim Game principle:
// Compute the XOR of all elements in the array.
// If XOR ≠ 0 → First player (Sita) wins.
// If XOR = 0 → Second player (Geeta) wins.
// 📥 Input Format
// First line contains a single integer N — the number of elements in the array.
// Second line contains N space-separated positive integers.
// 📤 Output Format
// Print:
// true → if Sita wins
// false → if Geeta wins
// Output must be in lowercase.
// 📌 Constraints
// 1 ≤ N ≤ 10^5
// 0 ≤ Ai ≤ 10^9

// 📝 Sample Input 1
// 3
// 1 2 3
// 📝 Sample Output 1
// false
// Explanation:
// 1 ^ 2 ^ 3 = 0

// Since XOR is 0, Sita loses → output is false.

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    int xorSum = 0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        xorSum ^= arr[i];
    }

    if(xorSum==0)
        cout<<"false";
    else
        cout<<"true";
    return 0;
}