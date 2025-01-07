#include <iostream>
using namespace std;

// Inline functions are used to reduce the function calls overhead

void func(int a,int b){
    a++;
    b++;
    cout<<a<<b<<endl;
}
inline int getMax(int a,int b){ // If function body is of only single line then make it inline
    return (a>b)?a:b; 
}
int main(){
    int a = 1,b = 2;
    // func(a,b); // memory usage --- Performance hit ---
    int ans = getMax(a,b);  // Because of inline no extra memory usage not more time required 
    cout<<ans<<endl;

    a = a + 3;
    b = b + 1;
    
    ans = getMax(a,b);
    cout<<ans<<endl;
    return 0;
}