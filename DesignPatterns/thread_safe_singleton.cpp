#include <iostream>
#include <mutex>
using namespace std;

//lock_guard is Exception-safe: guarantees unlock even if an exception is thrown.
class Singleton {
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> lock(mtx);//lock is automatically released at the end of scope of lock variable
            //alternately we can use mtx.lock()
            if (instance == nullptr) {
                instance = new Singleton();
            }
            //mtx.unlock()
        }
        return instance;
    }

private:
    Singleton() {
        cout << "Constructor called\n";
    }

    // Delete copy constructor and assignment operator to avoid copies
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* instance;
    static mutex mtx;
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* inst1 = Singleton::getInstance();
    Singleton* inst2 = Singleton::getInstance();
    cout << inst1 << " " << inst2 << "\n";
    return 0;
}
