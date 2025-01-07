#include <iostream>
using namespace std;

void sayDigit(int n,string *str){
    
    // Base Case
    if(n==0) 
      return ;

    // Processing 
    int num = n%10;
    n /= 10;
    
    // Recursive call
    sayDigit(n,str);

    cout<<str[num]<<" ";
}
int main(){
    string str[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cout<<"Enter number"<<endl;
    cin>>n;
    sayDigit(n,str);
    return 0;
}