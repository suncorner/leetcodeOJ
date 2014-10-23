// PalindromePartitioningII.cpp
//

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int minCut(string s);

int main(){

	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	int arrSize = sizeof(arr) / sizeof(int);
	string s = "bb";

	int cut = minCut(s);

	return 0;
}

int minCut(string s){
	const int n = s.size();
	bool *p = new bool[n * n];//Denote whether string[i,j] is palindrome
	int *cut = new int[n + 1];//Cut number for string[i, n-1]

	fill_n(p, n * n, false);
	for (int i = 0; i <= n; ++i){
		cut[i] = n - 1 - i;//Last one count[n] assigned -1
	}

	for (int i = n - 1; i >= 0; --i){
		for (int j = i; j < n; ++j){
			p[i * n + j] = s[i] == s[j] && (j - i < 2 || p[(i + 1) * n + j - 1]);
			if (p[i * n + j]){
				cut[i] = cut[j + 1] + 1 < cut[i] ? cut[j + 1] + 1 : cut[i];
			}
		}
	}
	int minCut = cut[0];

	delete[]p;
	delete[]cut;
	return minCut;

}

