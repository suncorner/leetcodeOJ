// 4Sum.cpp
//

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void twoSum(vector<int> &num, int target, int p, int r, vector<int> &bcPairs);
void threeSum(vector<int> &num, int target, int p, int r, vector<vector<int>> &triplets);
vector<vector<int> > fourSum(vector<int> &num, int target);

int main(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	int arr1[] = {1, 0, -1, 0, -2, 2};
	int arr1Size = sizeof(arr1) / sizeof(int);
	
	vector<int> ints(arr1, arr1 + arr1Size);
	int target = 0;

	vector< vector<int> > result = fourSum(ints, target);

	return 0;
}

void twoSum(vector<int> &num, int target, int p, int r, vector<int> &bcPairs)
{
	/*Assuming the vec &numbers is sorted and may contain dulplicates.*/

	int aa, count = 0;	//count for dulplicate's num
	int i = p, j = r;
	while (i < j){
		if (num[i] + num[j] == target){
			if (count == 0){	//value of num[i] first appearance
				bcPairs.push_back(num[i]);
				bcPairs.push_back(num[j]);
				++count;
				aa = num[i];
				++i;
			}
			else{
				while (i < j && num[i] == aa)	//filter this value which equals num[i]
					++i;
			}
		}
		else if (num[i] + num[j] < target){
			++i;
			count = 0;	//rules not satisfied, reset count to 0
		}
		else{
			--j;
			count = 0;	//rules not satisfied, reset count to 0
		}
	}
}

void threeSum(vector<int> &num, int target, int p, int r, vector<vector<int>> &triplets)
{
	/*Assuming the vec &num may contain dulplicates.*/

	if (r - p < 2)
		return;

	int a, aa;	//Variable aa to record a's previous value in order to avoid dulplicates

	for (int i = p; i < r - 1; ++i){
		a = num[i];
		if (i != p){
			aa = num[i - 1];
		}
		else{	//assign aa an arbitary value except a
			aa = !a;
		}
		vector<int> bcPairs;
		bcPairs.clear();
		twoSum(num, target - a, i + 1, r, bcPairs);
		if (a != aa){
			if (bcPairs.size() >= 2){
				for (int i = 0; i < bcPairs.size(); i += 2){
					triplets.push_back(vector<int> {a, bcPairs[i], bcPairs[i + 1]});
				}
			}
		}
	}
}

vector< vector<int> > fourSum(vector<int> &num, int target)
{
	/*Assuming the vec &num may contain dulplicates.*/
	
	vector< vector<int> > quadruplets;
	quadruplets.clear();

	if (num.size() <= 3)
		return quadruplets;

	sort(num.begin(), num.end());

	int a, aa;	//Variable aa to record a's previous value in order to avoid dulplicates
	int r = num.size() - 1;
	for (int i = 0; i < r - 2; ++i){
		a = num[i];
		if (i != 0){
			aa = num[i - 1];
		}
		else{	//assign aa an arbitary value except a
			aa = !a;
		}
		vector< vector<int> > triplets;
		triplets.clear();
		threeSum(num, target - a, i + 1, r, triplets);
		if (a != aa){	
			for (int j = 0; j < triplets.size(); ++j){
				quadruplets.push_back(vector<int> {a, triplets[j][0], triplets[j][1], triplets[j][2]});
			}
	
		}
	}

	return quadruplets;
}


