#include <iostream>
using namespace std;

int power(int a,int b){
    int ans = 1;
    for(int i=1;i<=b;i++){
      ans *= a;
    }
    return ans;
}

bool isEven(int num){
  if(num%2==0) return true;
  return false;
}

int factorial(int num){
  int fact = 1;
  while(num){
    fact *= num;
    num--;
  }
  return fact;
}

int ncr(int n,int r){
  int nF = factorial(n);
  int rF = factorial(r);

  int ans = (nF)/((rF)*factorial(n-r));
  return ans;
}

void printCounting(int n){
  for(int i=1;i<=n;i++)
     cout<<i<<" ";
  cout<<endl;
}

bool isPrime(int n){
  for(int i=2;i*i<n;i++){
    if(n%i==0)
      return false;
  }
  return true;
}

int nthTern(int n){
  return 3*n+7;
}

int totalSetBits(int a,int b){
  int setBit=0,r;
  while(a){
    r = a%2;
    if(r==1)
      setBit++;
    a /= 2;
  }
  while(b){
    r = b%2;
    if(r==1)
      setBit++;
    b /= 2;
  }
  return setBit;
}

int fibonacci(int n){
  int a=0,b=1;
  for(int i=2;i<n;i++){
    int next = a+b;
    a = b;
    b = next;
  }
  return b;
}

int main(){
  // cout<<power(2,3)<<endl;
  cout<<power(2,10)<<endl;
  /*
  if(isEven(6)){
    cout<<"Even number";
  }
  else{
    cout<<"Odd number";
  }
  */
  // cout<<ncr(8,2)<<endl;
  cout<<ncr(13,0)<<endl;
  printCounting(10);
  /*
  if(isPrime(23))
    cout<<"is a prime number";
  else
    cout<<"not a prime number";
  */
  // cout<<nthTern(5)<<endl;
  cout<<nthTern(3)<<endl;
  cout<<totalSetBits(2,3)<<endl;
  // cout<<fibonacci(5)<<endl;
  cout<<fibonacci(7)<<endl;
  return 0;
}