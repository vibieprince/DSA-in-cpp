#include<iostream>
#include<vector>
#include<math.h>
#include <string.h>
using namespace std;
vector<int> SieveOfEratosthenes(int n){
    //Initialise with 1(assuming all numbers are prime initially)
    vector<int> prime(n+1,true);
    prime[0]=prime[1]=false;

    // Apply Sieve of Eratosthenes
    for(int i=2;i<= sqrt(n);++i){
        if(prime[i]==true){
            for(int j=i*i;j<=n;j+=i)
              prime[j] = false;
        }
    }
    vector<int> ans;
    // collect prime numbers
    for(int i=2;i<=n;i++){
        if(prime[i]==true)
           ans.push_back(i);
    }
    return ans;

}
int main(){
    int n = 1000;
    vector<int>primes = SieveOfEratosthenes(n);
    cout<<"Following are the Prime numbers smaller than or equal to "<<n<<endl;
    for(int prime : primes)
      cout<<prime<<" ";
}
