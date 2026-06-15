// Star Chart Rotator
// An astronomy observatory uses an n x n star chart grid to map the positions of celestial objects. Each cell chart[r][c] holds the brightness rating of a star or deep-sky object at that grid position (negative values represent calibration offsets, zero means empty sky).

// When the telescope mount rotates 90 degrees clockwise, the star chart must be updated to reflect the new orientation. You must rotate the chart in-place — you cannot allocate a new grid.

// Given the n x n star chart, rotate it 90 degrees clockwise in-place and print the resulting chart.

// Input Format First line: a single integer n — the dimension of the chart Next n lines: each line contains n space-separated integers representing a row of the chart Output Format Print n lines, each containing n space-separated integers — the star chart after 90-degree clockwise rotation.

// Example 1

// Input: 3 1 2 3 4 5 6 7 8 9

// Output: 7 4 1 8 5 2 9 6 3

// Explanation: The 3x3 star chart is rotated 90 degrees clockwise. The first column (7, 4, 1) read bottom-to-top becomes the first row of the result

// Example 2 Input: 4 5 1 9 11 2 4 8 10 13 3 6 7 15 14 12 16 Output: 15 13 2 5 14 3 4 1 12 6 8 9 16 7 10 11

// Example 3 Input: 2 1 2 3 4 Output: 3 1 4 2

// Example 4 Input: 1 42 Output: 42

// Example 5 Input: 3 0 -1 -2 5 6 7 8 9 10 Output: 8 5 0 9 6 -1 10 7 -2

// Example 6 Input: 5 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 Output: 21 16 11 6 1 22 17 12 7 2 23 18 13 8 3 24 19 14 9 4 25 20 15 10 5

// Constraints 1 <= n <= 20 -1000 <= chart[r][c] <= 1000 Rotation must be performed in-place (no auxiliary grid of the same size)

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }

    // First do transponse
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++)
            swap(arr[i][j],arr[j][i]);
    }

    // Now reverse each row;
    int k = n;
    for(int i=0;i<n;i++){
        k = n-1;
        for(int j=0;j<n;j++){
            if(j==n/2) break;
            swap(arr[i][j],arr[i][k]);
            k--;
        }
    }

    // Printing the array
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}