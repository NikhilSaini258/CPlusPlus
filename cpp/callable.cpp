#include <bits\stdc++.h>
using namespace std;

void fun() {
    cout << "fun()" << endl;
}

static void stat() {
    cout << "stat()" << endl;
}

class ABCD {
public:
    void fun() {            // non-static method
        cout << "ABCD::fun()" << endl;
    }
    static void stat() {    // static method
        cout << "ABCD::stat()" << endl;
    }
};

void check(void (*fun__)())
{
    (*fun__)();        // calling function pointer fun__ which is passed to this function
    //fun();           // same as above
}

void check2(void (ABCD::*fun__)(), ABCD obj)
{
    /*  Object of class ABCD is require in this case, as ABCD::fun is non-static (so, non-shareable).
        So, every object have its own copy of ABCD::fun. 
        We, need to use object to call this method/function pointer.
    */
    (obj.*fun__)();     // calling method pointer fun__ in the state of object obj
    //obj.fun();        // same as above
}

int main() 
{
    check(&fun);        // passing function pointer of &fun to check
    check(&stat);       // passing static mthod pointer of &stat to check

    void (*meth)() = &fun;
    void (ABCD:: * method) () = &ABCD::fun;
    ABCD obj;

    (obj.*(&ABCD::fun))();
    //(obj.*method)();  // same as above

    check2(method, obj);

    check(&ABCD::stat); // passing static method pointer ABCD::stat
                        // static are shared. so there states are not depends on any object.
                        // thats why we can call it directly, without any object.

    return 0;
}