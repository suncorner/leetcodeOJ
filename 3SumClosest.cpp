// 3SumClosest.cpp
//

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int> &num, int target);

int main(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	int arr1[] = {1, 1, 1, 1};
	int arr1Size = sizeof(arr1) / sizeof(int);

	vector<int> ints(arr1, arr1 + arr1Size);
	int target = 3;

	int result = threeSumClosest(ints, target);
	
	return 0;
}

int threeSumClosest(vector<int> &num, int target)
{
	int closest, offset = INT_MAX;

	if (num.size() < 3)
		return 0;

	sort(num.begin(), num.end());
	
	int a, b, c;
	for (int i = 0; i < num.size() - 2; ++i){
		int j = i + 1, k = num.size() - 1;
		while (j < k){
			a = num[i]; b = num[j]; c = num[k];
			if (abs(a + b + c - target) < offset){
				closest = a + b + c;
				offset = abs(closest - target);
				if (offset == 0)
					goto L1;
			}
			else if (a + b + c - target < 0){
				++j;
			}
			else if (a + b + c - target > 0){
				--k;
			}
		}
	}
L1:
	return closest;
}


