#include <iostream>
using namespace std;

int main(){
    // Pattern 1
    // int i = 1;
    // while(i<4){
    //     int j = 3;
    //     while(j>0){
    //         cout<<j<<" "; //or can do with n-j+1
    //         j--;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 2 
    // int i = 1;
    // int j = 1;
    // while(i<4){
    //     while(j<=i*3){
    //         cout<<j<<" ";
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }
    
    // Pattern 3
    // int i = 1;
    // while(i<5){
    //     int j = 1;
    //     while(j<=i){
    //         cout<<"* ";
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 4
    // int i = 1;
    // while(i<5){
    //     int j = 1;
    //     while(j<=i){
    //         cout<<i<<" ";
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }
    
    // Pattern 5 
    // int i = 1;
    // int count = 1;
    // while(i<5){
    //     int j = 1;
    //     while(j<=i){
    //         cout<<count<<" ";
    //         count++;
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern '6 
    // int i = 1;
    // while(i<5){
    //     int count = i;
    //     int j = 1;
    //     while(j<=i){
    //         cout<<count<<" ";
    //         count++;
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 7
    // int i = 1;
    // while(i<5){
    //     int count = i;
    //     int j = 1;    //or do with i-j+1
    //     while(j<=i){
    //         cout<<count<<" ";
    //         count--;
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 8 
    // int i = 1;
    // char ch = 'A';
    // while(i<4){
    //     int j = 1;
    //     while(j<4){
    //         cout<<ch<<" ";
    //         j++;
    //     }
    //     ch++;
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 9 
    // int i = 1;
    // while(i<4){
    //     char ch = 'A';
    //     int j = 1;
    //     while(j<4){
    //         cout<<ch<<" ";
    //         ch++;
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 10 
    // char ch = 'A';
    // int i = 1;
    // while(i<4){
    //     int j = 1;
    //     while(j<4){
    //         cout<<ch<<" ";
    //         ch++;
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 11
    // int i = 0;
    // while(i<3){
    //     int j = 0;
    //     char ch = 'A'+i;
    //     while(j<3){
    //         cout<<ch<<" ";
    //         ch++;
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 12
    // int i = 1;
    // char ch = 'A';
    // while(i<4){
    //     int j = 1;
    //     while(j<=i){
    //         cout<<ch<<" ";
    //         j++;
    //     }
    //     ch++;
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 13
    // int i = 1;
    // char ch = 'A';
    // while(i<5){
    //     int j = 1;
    //     while(j<=i){
    //         cout<<ch<<" ";
    //         j++;
    //         ch++;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 14
    // int i = 0;
    // while(i<4){
    //     char ch = 'A'+i;
    //     int j = 0;
    //     while(j<=i){
    //         cout<<ch<<" ";
    //         ch++;
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 15
    // int i = 0;
    // while(i<4){
    //     char ch = 'D'-i;
    //     int j = 0;
    //     while(j<=i){
    //         cout<<ch<<" ";
    //         ch++;
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 16
    // int i = 5;
    // while(i>0){
    //     int space = i;
    //     while(space>0){
    //         cout<<" ";
    //         space--;
    //     }
    //     int j = 6-i;
    //     while(j>0){
    //         cout<<"*";
    //         j--;
    //     }
    //     i--;
    //     cout<<endl;
    // }

    // Pattern 17
    // int i = 5;
    // while(i>0){
    //     int j = 0;
    //     while(j<i){
    //         cout<<"* ";
    //         j++;
    //     }
    //     i--;
    //     cout<<endl;
    // }

    // Pattern 18 
    // int i = 0;
    // while(i<5){
    //     int space = i;
    //     while(space>0){
    //         cout<<" ";
    //         space--;
    //     }
    //     int j = 5-i;
    //     while(j>0){
    //         cout<<"*";
    //         j--;
    //     }
    //     i++;
    //     cout<<endl;
    // }
    
    // Pattern 19 
    // int i = 5;
    // int num = 1;
    // while(i>0){
    //     int space = i;
    //     while(space>0){
    //         cout<<" ";
    //         space--;
    //     }
    //     int j = 6-i;
    //     while(j>0){
    //         cout<<num;
    //         j--;
    //     }
    //     num++;
    //     i--;
    //     cout<<endl;
    // }
    
    // Pattern 20 
    // int i = 1;
    // while(i<5){
    //     int space = 4-i;
    //     while(space>0){
    //         cout<<" ";
    //         space--;
    //     }
    //     int j = 1;
    //     while(j<=i){
    //         cout<<j;
    //         j++;
    //     }
    //     int k = i-1;
    //     while(k>0){
    //         cout<<k;
    //         k--;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    // Pattern 21
    // 1234554321
    // 1234**4321
    // 123****321
    // 12******21
    // 1********1
    // int i = 5;
    // while(i>0){
    //     int j = 1;
    //     while(j<=i){
    //         cout<<j;
    //         j++;   
    //     }
    //     int star = 2*(5-i);
    //     while(star>0){
    //         cout<<"*";
    //         star--;
    //     }
    //     j = i;
    //     while(j>0){
    //         cout<<j;
    //         j--;
    //     }
    //     i--;
    //     cout<<endl;
    // }
    
    return 0;
}