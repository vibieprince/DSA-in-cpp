// // Problem statement : Return maximum occuring character in an input string
// #include<bits/stdc++.h>
// char MaxOccurences(char s[]){
//     int arr[26] = {0};
//     for(int i=0;i<26;i++){
//         char ch = s[i];
//         int number = 0;

//         //Lower case
//         if(ch>='a' && ch<='z')
//            number = ch - 'a';

//         // Upper Case 
//         else
//            number = ch - 'A';
//         arr[number]++;
//     }
//     int maxi = -1,ans=0;
//     for(int i=0;i<strlen(s);i++){
//         if(maxi < arr[i]){
//             ans = i;
//             maxi = arr[i];
//         }
//     }
//     char finalAns = 'a'+ans;
//     return finalAns;
// }
// using namespace std;
// int main(){
//     char s[20];
//     cout<<"Enter a string : ";
//     cin>>s;
//     cout<<MaxOccurences(s)<<endl;
// }