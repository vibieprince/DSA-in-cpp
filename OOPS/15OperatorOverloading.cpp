#include<iostream>
using namespace std;
class Operate{
    public:
    int y = 10;
    int x = y;
    
    string a = "Prince";
    string b = a;
};
int main(){
    Operate o1;
    cout<<o1.x<<endl;
    cout<<o1.y<<endl;
    cout<<o1.a<<endl;
    cout<<o1.b<<endl;
}