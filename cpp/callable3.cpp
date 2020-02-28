#include <bits/stdc++.h>
using namespace std;

int main()
{
	// We cannot pass static and global variables in capture list of lambda.
    // As, static variables cannot be initialized in constructor.
    // And, global varibales already available inside lambda also. Therefore no need to pass them in capture list.
	
    // It is not recommended to take type of lambda, as it may be implemented using function pointer when no state need to store,
    // or may be implemented by functors when we store a state.
    // It is always better to use auto for lambda type as below:
    // auto l = [] () {}

    // below 3 methods are same, just way of doing is different. Consider it for understanding function pointer, not for understanding lambda

    // 1. Create a typedef then use variable, created in typedef as below
    typedef int(*functionPointer)(int, int);
    functionPointer p = [](int a, int b) ->int { cout << "Lambda: " << a + b << endl; return a + b; };
    p(3, 5);

    // 2. Create a function pointer and use name given to function pointer
    int(*funtionPointerName)(int, int);
    funtionPointerName = [](int a, int b) ->int { cout << "Lambda: " << a + b << endl; return a + b; };
    funtionPointerName(2, 3);

    // 3. create function pointer in place when assigning lambda to it.
    int(*funtion)(int, int) = [](int a, int b) ->int { cout << "Lambda: " << a + b << endl; return a + b; };
    funtion(3, 4);

    // 4. below case won't work, as I dont know, how to create lambda type in this case
    int c = 7;
    auto lambda = [c](int a, int b) ->int { cout << "Lambda: " << a + b + c << endl; return a + b + c; };
    cout << lambda(4, 4) << endl;
    
    return 0;
}



