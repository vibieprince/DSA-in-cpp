#include<iostream>
using namespace std;
class Print{
    public:
    void show(int x){
        cout<<"Integer : "<<x<<endl;
    }
    void show(char c){
        cout<<"Character : "<<c<<endl;
    }
};
int main(){
    Print p1;
    p1.show(9);
    p1.show('C');
    return 0;
}