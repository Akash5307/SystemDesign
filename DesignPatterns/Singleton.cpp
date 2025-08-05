//This is not thread safe
#include<bits/stdc++.h>
using namespace std;

class Singleton{
    public:
    static Singleton* getInstance(){
        if(instance==nullptr){
            instance=new Singleton();
        }
        return instance;
    }
    private:
    Singleton() {
        cout << "Constructor called\n";
    }

    // Delete copy constructor and copy assignment operator to avoid copies
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* instance;
};

Singleton* Singleton::instance=nullptr;
int main(){
    Singleton* inst1=Singleton::getInstance();
    Singleton* inst2=Singleton::getInstance();
    //Singleton inst3=*inst1;

    //*inst2=*inst1 not permitted due to copy assignment operator definition
    cout<<inst1<<" "<<inst2<<"\n";
    return 0;
}
