#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "number.h"
using namespace std;

int globalNumToFind;
vector<Number> globalResult;
void findNum(Number num){
    it(num.Value() > globalNumToFind)
    globalResult.push_back(num);
}

class NumberFinder{
public:
    NumberFinder(int n, vector<Number>& r) : numToFind(n), result(r) {}
    void operator() (Number num){
        if(num.Value() > numToFind)
            result.push_back(num.Value());
    }
private:
    int numToFind;
    vector<Number>& result;    
};

int main()
{
    vector<Number> numVect = {2,3,4,5,6,7};
    
    auto status = find(numVect.begin(), numVect.end(), 5);
    if(status != numVect.end())
        cout << "Found Value in Vector" << endl;
    else
        cout << "Didn't found value" << endl;
    
    globalNumToFind = 4;
    find_if(numVect.begin(), numVect.end(), findNum);
    for(auto val : globalResult)
        cout << val << "*";
    cout << endl;
    
    vector<Number> findVec;
    NumberFinder finder(4, findVec);
    find_if(numVect.begin(), numVect.end(), finder);
    for(auto val : findVec)
        cout << val << "*";
    cout << endl;
    
    
    return 0;
}