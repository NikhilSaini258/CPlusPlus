#include "number.h"
using namespace std;

class NumberFinder{
	public:
		NumberFinder(int n, vector<Number>& r):numToFind(n),result(r){}
		void operator()(Number num){
			if (num.Value() > numToFind)
				result.push_back(num);
		}
	private:
		int numToFind;
		vector<Number>& result;	
}

void main(){
	vector<Number> numVec = {5,8,1,6,3,7};
	vector<Number> resultVec;
	NumberFinder numFind(4, resultVec);
	for_each(numVec.begin(), numVec.end(), numFind )
	
}