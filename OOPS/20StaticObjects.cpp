#include<iostream>
using namespace std;
class ABC{
    public:
    ABC(){
        cout<<"Constructor"<<endl;
    }
    ~ABC(){
        cout<<"Destructor"<<endl;
    }
};
int main(){
    if(1){
        static ABC obj;
    }
    cout<<"End of main function"<<endl;
    return 0;
    // When static keyword is not used
    // Output --> Constructor
            //   Destructor 
            //   End of main function

    // When static keyword is used
    // Output --> Constructor
             //   End of main function
             //   Destructor 

}
// after all apart from these 
// there are friend functions and friend class which you may study yourselves
