#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char tolower(char ch){
    if(ch>='a' && ch<='z')
       return ch;
    else{
        char temp = ch - 'A'+'a';
        return temp;
    }
}
bool isPalindrome(char name[]){
    int s=0,e=strlen(name)-1;
    while(s<e){
        if(tolower(name[s])!=tolower(name[e]))
          return 0;
        s++;
        e--;
    }
    return 1;
}
int getLength(char *name){
    int i=0;
    while(name[i]!='\0'){
        i++;
    }
    return i;
}
void reverseString(char name[]){
    int start=0,end=getLength(name)-1;
    while(start<end)
      swap(name[start++],name[end--]);
}
int main(){
    char name[20];
    cout<<"Enter your name : ";
    cin>>name;
    reverseString(name);
    cout<<"Your name is : "<<name<<endl;
    cout<<"Length of string : "<<getLength(name)<<endl;
    if(isPalindrome(name))
      cout<<"String is a Palindrome";
    else 
      cout<<"String is not a Palindrome";
}