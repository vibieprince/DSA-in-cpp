#include <iostream>
using namespace std;

void reachHome(int src,int dest){
    cout<<"Source "<<src<<" destination "<<dest<<endl;
    // Base case -- rukna kab hai
    if(src==dest){
       cout<<"pahuch gya"<<endl;
       return ;
    }
    // Processing - ek step aage badhjao
    src++;

    // Recursive call
    reachHome(src,dest);
    
}
int fibo(int n){
    if(n==1) // Base case 
       return 0;
    if(n==2) // Base case
       return 1;
    return fibo(n-1)+fibo(n-2);
}
int main(){
    int src = 1;
    int dest = 10;

    reachHome(src,dest);
    return 0;
}