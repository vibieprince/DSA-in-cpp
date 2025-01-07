#include<iostream>
using namespace std;
void update(int **ptr2){
    // ptr2 = ptr2 + 1;
    // kuch change hoga - NO

    // *ptr2 = *ptr2 + 1;
    // kuch change hoga - YES

    **ptr2 = **ptr2 + 1;
    // kuch change hoga - YES
}
int main(){
    int i = 5;
    // Normal pointer
    int *ptr = &i;

    // Double pointer
    int **ptr2 = &ptr;

    // Triple pointer
    int ***ptr3 = &ptr2;
    
    // and so on we can make such multilevel pointers

    // cout<<"Printing ptr "<<ptr<<endl; // Address of i
    // cout<<"Adress of ptr "<<&ptr<<endl; // Address of ptr
    // cout<<"Value of ptr2 "<<*ptr2<<endl; // Address of i
    // cout<<endl;
    // cout<<"Printing ptr2 "<<ptr2<<endl; //Address of ptr
    // cout<<"Address of ptr2 "<<&ptr2<<endl; // Address of ptr2
    // cout<<"Value of ptr3 "<<*ptr3<<endl; // Address of ptr
    // cout<<endl;

    cout<<"Before "<<i<<endl;
    cout<<"Before "<<ptr<<endl;
    cout<<"Before "<<ptr2<<endl;
    update(ptr2);
    cout<<"After "<<i<<endl;
    cout<<"After "<<ptr<<endl;
    cout<<"After "<<ptr2<<endl;

}