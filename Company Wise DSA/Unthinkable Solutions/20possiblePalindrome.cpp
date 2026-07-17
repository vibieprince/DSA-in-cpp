#include<iostream>
#include<vector>
using namespace std;

int main(){
    string str;
    cin>>str;

    vector<int> freq(256,0);
    for(char &c : str)
        freq[c]++;

    int oddCount = 0;
    for(int &i : freq)
        if(i%2)
            oddCount++;

    cout<<(oddCount<=1 ? "true" : "false");
}