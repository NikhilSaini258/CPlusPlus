#include <bits/stdc++.h>
using namespace std;

template<class T, class Container = std::deque<T>>
class Stack {
public:
    Stack() : Stack(Container()) {
        cout << "Stack()" << endl;
        //cout << print(Container()) << endl;   // calls the "print" method with "Container" passed as parameter
    }
    /*explicit*/ Stack(const Container& cont) { cout << "Stack(const Container& cont)" << endl; };
    bool print(const Container& cont) { return false; }
};

void fun(Stack<int, vector<int>> s) {
    cout << "Stack fun()" << endl;
}

void fun2(vector<int> v) {
    cout << "Vector fun()" << endl;
}

int main()
{
    vector<int> v;
    Stack<int, vector<int>> s;         // calls default constructor which result in calling of parameterized constructor
    //Stack<int, vector<int>> s2(v);   // calls parameterized constructor

    //fun2(v);                         // prints "vector", which is fine

    //fun(s);                          // prints "stack", which is fine
    fun(v);                            // prints "stack", when constructor is not explicit, which is wrong
                                       // This is the reason of putting, explicit constructor in std::stack od STL
    
    /* The constructors are explicit so you can't accidentally pass an underlying container (such as vector or deque) 
    to a function expecting a stack, resulting in unexpected copying (not to mention violating the principle of least surprise). */

    return 0;
}

/* If a class has a constructor which can be called with a single argument, then this constructor becomes conversion constructor 
   because such a constructor allows conversion of the single argument to the class being constructed.

Example of implicit and explicit calls
class ABC{
public:
    ABC(int) {}
};

ABC o2 = 100;          // implicit call
ABC o1 = ABC(100);     // explicit call by type-casting

*/
