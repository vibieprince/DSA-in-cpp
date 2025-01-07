#include <iostream>
using namespace std;

// int factorial(int n){
//     // base case
//     if(n==0)
//       return 1;
//     int smallProblem = factorial(n-1);
//     int biggerProblem = n*smallProblem;

//     return biggerProblem;
// }

// int power(int n){
//   // base case
//   if(n==0)
//     return 1;

//   int smallerProb = power(n-1);
//   int biggerProb = 2*smallerProb;

//   return biggerProb;
// }

int power(int n){
  // base case
  if(n==0)
    return 1;
  
  return 2*power(n-1);
}

int factorial(int n){
    if(n==0)
      return 1;
    return n*factorial(n-1);
}

// int print(int n){ //Tail Recursion
//   if(n==0)
//     return 1;
  
//   cout<<n<<endl; 

//   print(n-1);
// }
int print(int n){ // Head Recursion
  if(n==0)
    return 1;
  
  print(n-1);

  cout<<n<<endl;
}
int main(){
    int n;
    cin>>n;
    int ans = factorial(n);
    cout<<ans<<endl;

    int m;
    cin>>m;
    cout<<power(m)<<endl;

    print(5);
    return 0;
}