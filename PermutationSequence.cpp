// PermutationSequence.cpp
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string getPermutation(int n, int k);
string intVecToString(int A[], int size);

int main(){

	string result = getPermutation(4, 19);

	return 0;
}

string intVecToString(int A[], int size)
{
	string str = "";
	char tmp[16];
	string strTmp;
	for (int i = size - 1; i >= 1; --i){
		str += std::to_string(A[i]);
	}
	return str;
}

string getPermutation(int n, int k)
{
	/*Calc Fact Table for later look-up*/
	int fact[10] = {1, 1};
	for (int i = 2; i <= n; ++i){
		fact[i] = fact[i - 1] * i;
	}

	if (n < 1 || n > 9 || k < 1 || k > fact[n])
		return "";

	int offset[10];
	int order = k - 1, i = n - 1;
	while (i > 0){
		offset[i + 1] = order / fact[i];
		order -= offset[i + 1] * fact[i];
		--i;
	}
	offset[1] = order;

	vector<int> kthSmallests;
	for (int i = 1; i <= n; ++i)
		kthSmallests.push_back(i);

	int result[10];
	for (int i = n; i > 0; --i){
		result[i] = kthSmallests[offset[i]];
		kthSmallests.erase(kthSmallests.begin() + offset[i]);
	}

	string str = intVecToString(result, n + 1);

	return str;
	
}
