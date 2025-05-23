#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define MAX 100001
vector<int>*sieve(){
    bool isPrime[MAX];
    for(int i=0;i<MAX;i++){
        isPrime[i] = true;
    }
    for(int i=2;i<sqrt(MAX);i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j++)
                isPrime[j] = false;
        }
    }
    vector<int>*primes = new vector<int>();
    primes.push_back(2);
    for(int i=3;i<MAX;i+=2){
        if(isPrime[i])
          primes->push_back(i);
    }
    return primes;
}
void printPrimes(long long l,long long r,vector<int>* &primes){
    bool isPrime[r-l+1];
    for(int i=0;i<=r;i++){
        isPrime[i] = true;
    }
    for(int i=0;primes->at(i)*(long long)primes->at(i)<=r;i++){
        int currPrime = prime->at(i);
        // just smaller or equal value to l
        long long base = (l/(currPrime))*(currPrime);
        if(base<l)
           base = base + currPrime;
        // Mark all multiples within L to R as false
        for(long long j = base;j<=r;j+=currPrime)
          isPrime[j-l] = false;
        // There may be a case where base is itself a Prime number.
        if(base == currPrime)
          isPrime[base-l] = true;
    }
    for(int i=0;i<=r-l;i++){
        if(isPrime[i] == true)
          cout<<i+l<<endl;
    }
}
int main(){
    vector<int>*primes = sieve();
    int t;
    cin>>t;
    while(t--){
        long long l,r;
        cin>>l>>r;
        printprimes(l,r,primes);
    }
    return 0;
}