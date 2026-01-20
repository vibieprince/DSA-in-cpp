// There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

// You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

// Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

// Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

// Input: tickets = [2,3,2], k = 2

// Output: 6

// Explanation:

// The queue starts as [2,3,2], where the kth person is underlined.
// After the person at the front has bought a ticket, the queue becomes [3,2,1] at 1 second.
// Continuing this process, the queue becomes [2,1,2] at 2 seconds.
// Continuing this process, the queue becomes [1,2,1] at 3 seconds.
// Continuing this process, the queue becomes [2,1] at 4 seconds. Note: the person at the front left the queue.
// Continuing this process, the queue becomes [1,1] at 5 seconds.
// Continuing this process, the queue becomes [1] at 6 seconds. The kth person has bought all their tickets, so return 6.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    queue<int> q;
    for(int i=0;i<tickets.size();i++)
        q.push(i);

    int time = 0;
    while(!q.empty()){
        int person = q.front();
        q.pop();

        tickets[person]--;
        time++;

        if(tickets[person]>0) // still left to buy more
            q.push(person);
        
        else if(person==k)
            break;
    }
    return time;
}

int main(){
    int x,k;
    vector<int> tickets;
    while(cin>>x)
        tickets.push_back(x);
    k = tickets.back();
    tickets.pop_back();
    int ans = timeRequiredToBuy(tickets,k);
    cout<<ans;
}