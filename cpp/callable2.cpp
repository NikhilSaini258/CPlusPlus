#include <bits/stdc++.h>
using namespace std;

void fun() {
    cout << "fun()" << endl;
}

class ABC{
public:
    void operator()() {
        cout << "void operator()()" << endl;
    }
};

// We cannot directly pass functors, as of my knowledge.
// So we directly pass class object (void printUsingObject) or pointer of object (void printUsingPointer) instead of passing functors 
// but we can pass function pointer, there is no such restriction like functors
void printUsingPointer(ABC* fun__){
    (*fun__)();
}

void printUsingObject(ABC obj__){
    (obj__)();
    //obj__();      // same as above
}

void printUsingStdFunction(std::function<void()> fun){
	// using std::function which was introduced in c++11
	// It takes all types of callable
	// 1. function pointer
	// 2. functors
	// 3. lambda
    fun();
}

int main()
{
    ABC obj;
    obj();

    printUsingPointer(&obj);
    printUsingObject(obj);

    printUsingStdFunction(fun);			// calling same method using function pointer
    printUsingStdFunction(obj);			// calling same method using functors
    printUsingStdFunction([]() {		// calling same method using lambda
		cout << "from labmda" << endl; 
		});
    
    
    return 0;
}



