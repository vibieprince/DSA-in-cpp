#include<iostream>
#include<vector>
using namespace std;


int characterReplacement(string s, int k) {
    vector<int> freq(26,0);
    int i=0,maxCount=0,result=0;
    for(int j=0;j<s.length();j++){
        freq[s[j]-'A']++;
        maxCount = max(maxCount,freq[s[j]-'A']);
        while(j-i+1-maxCount>k){
            freq[s[i]-'A']--;
            i++;
        }
        result = max(result,j-i+1);
    }
    return result;
}

int main(){
    string s;
    cin>>s;

    int k;
    cin>>k;

    cout<<characterReplacement(s,k);
    return 0;
}