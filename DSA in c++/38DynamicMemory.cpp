#include<iostream>
using namespace std;
int main(){
    // Stack mein hota hai static allocation
    // Heap mein hota hai dynamic allocation 

    // Heap hamesha address deta hai;
    // new char;
    // char * ch = new char;
    char ch = 'a';
    cout<<sizeof(ch)<<endl;

    char *c = &ch;
    cout<<sizeof(c)<<endl;

    return 0;
}