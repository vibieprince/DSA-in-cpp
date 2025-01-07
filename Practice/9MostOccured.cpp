#include <iostream>
using namespace std;

char MostOccured(string s){
    int arr[26] = {0};

    // create an array count of character
    for(int i=0;i<s.length();i++){
        int num = 0;
        char ch = s[i];
        if(ch >= 'a' && ch <='z')
           num = ch - 'a';
        else
           num = ch - 'A';
        arr[num]++;

    }
    int maxi = -1,ans = -1;
    for(int i=0;i<26;i++){
        if(maxi < arr[i]){
           ans = i;
           maxi = arr[i];
        }
    }
    char finalAns = 'a' + ans;
    return finalAns;
}
int main(){
    string s;
    cout<<"Enter a string : ";
    cin>>s;
    cout<<MostOccured(s);
    return 0;
}