// Problem Statement -:  There are N Homeless people in the community and N houses in the community. It will be given in the array (people), the height of the person, and in the array house capacity of the house is given.

// The government decided to give homes to people on the basis of the following conditions:

// Priority is given to the people from left to right of the array
// Each person is allotted to a house if and only if the capacity of the house is greater than or equal to the person’s height
// Nearby empty Houses are allotted to the person( starting from the extreme left)
// You need to find the number of homeless people who have not been allotted any home if the government follows the above conditions. So that government will have an idea of how many people they need to allot homes for next time.

// Input Format for Custom Testing:

// The first line contains an integer, N, denoting the number of  people and number of houses.
// Each line i of the N subsequent lines (where 0 <= i <= N) contains an integer describing peoplei.
// Each line i of the N subsequent lines (where 0 <= i <= N) contains an integer describing housei.
// Sample Test Cases

// Sample Input 1
// 3  
// 4
// 2
// 7
// 3
// 5
// 10
// Sample Output 1
// 0
// Explanation
// people=[4,2,7]
// house=[3,5,10]
// People[0] has more priority , from left to right order in houses 5 is the nearest one which fits for people[0]
// people[1]=2 will fit in 3 which is nearer from left
// people[2]=7 will fit in remaining house of capacity of 10
// So no homeless people left so return 0 

#include<iostream>
#include<vector>
#include<set>
using namespace std;

// O(N^2)
int findHomeless(vector<int> &people,vector<int> &house){
    int count = 0;
    for(int i=0;i<people.size();i++){
        for(int j=0;j<house.size();j++){
            if(people[i]<=house[j]){
                count++;
                house[j] = -1;
                break;
            } 
        }
    }   
    return people.size()-count;
}

// O(NlogN)
int findHomeless2(vector<int>&people,vector<int> &house){
    multiset<int> ms(house.begin(),house.end());
    // Multiset is created by Red Black Tree
    // Used for ordered sets and allowed duplicates
    int homeless = 0;
    for(int p : people){
        auto it = ms.lower_bound(p); // for >= 
        if(it==ms.end())
            homeless++;
        else
            ms.erase(it); // that house is removed from the multiset
    }
    return homeless;
}

int main(){
    int N,x;
    cin>>N;
    vector<int> people;
    vector<int> house;
    for(int i=0;i<N;i++){
        cin>>x;
        people.push_back(x);
    }
    for(int i=0;i<N;i++){
        cin>>x;
        house.push_back(x);
    }
    return 0;
}