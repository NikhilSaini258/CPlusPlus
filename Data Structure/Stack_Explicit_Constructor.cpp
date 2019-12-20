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
    //us.insert(10, 20, 11, 34, 99, 86);
    vector<int> v;
    Stack<int, vector<int>> s;
    //Stack<int, vector<int>> s2(v);   // calls parameterized constructor

    //fun2(v);                         // prints "vector", which is fine

    //fun(s);                          // prints "stack", which is fine
    fun(v);                            // prints "stack", when constructor is not explicit, which is wrong
                                       // This is the reason of putting, explicit constructor in std::stack od STL

    return 0;
}
