// Online assessment of AutoDesk

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// int possibleWays(vector<int> &primary,vector<int> &secondary,int targetSum){
//     unordered_map<int,int> map;
//     for(int i : secondary)
//         map[i]++;

//     int ways = 0;
//     for(int i : primary){
//         int need = targetSum - i;
//         if(map.count(need))
//             ways += map[need];
//     }
//     return ways;
// }
// vector<int> processQueries(vector<int> primary,vector<int> secondary,vector<vector<int>> opeartions){
//     vector<int> result;
//     for(vector<int> &i : opeartions){
//         if(i[0]==1)
//             result.push_back(possibleWays(primary,secondary,i[1]));
//         else
//             secondary[i[1]] = i[2];
//     }
//     return result;
// }

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> processQueries(vector<int> primary, vector<int> secondary, vector<vector<int>> operations) {
    unordered_map<int,int> freq;
    
    // build freq map once
    for(int x : secondary)
        freq[x]++;

    vector<int> result;
    
    for(auto &op : operations){        
        if(op[0] == 1){
            int target = op[1];
            int ways = 0;
            for(int p : primary){
                int need = target - p;
                if(freq.count(need))
                    ways += freq[need];
            }
            result.push_back(ways);
        }
        else {
            int index = op[1];
            int newVal = op[2];
            
            int oldVal = secondary[index];
            // remove old value
            freq[oldVal]--;
            if(freq[oldVal] == 0)
                freq.erase(oldVal);
            // add new value
            freq[newVal]++;
            secondary[index] = newVal;
        }
    }
    return result;
}