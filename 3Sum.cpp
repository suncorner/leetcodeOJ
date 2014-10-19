// 3Sum.cpp
//

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(multimap<int, int> &numbers, multimap<int, int>::iterator begin, int target);
vector<vector<int>> threeSum(vector<int> &num);

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int arr1[] = { -100, 0, 1, 1, 1, 2, 2, 3, 4, 90, 90, 96, 97, 97, 98, 99, 99, 100};
	int arr1Size = sizeof(arr1) / sizeof(int);
	
	vector<int> ints(arr1, arr1 + arr1Size);
	int target = 9;

	vector<vector<int>> vvI = threeSum(ints);
	
	return 0;
}

vector<int> twoSum(vector<int> &numbers,
			vector<int>::iterator itP, vector<int>::iterator itR, int target) 
{
	/*Assuming the vec &numbers is sorted and may contain dulplicates.*/

	vector<int> result;
	result.clear();
	int aa, count = 0;//count for dulplicate's num

	while (itP < itR){
		if (*itP + *itR == target){
			if (count == 0){	//value of *itP first appearance
				result.push_back(*itP);
				result.push_back(*itR);
				++count;
				aa = *itP;
				++itP;
			}
			else{
				while (itP < itR && *itP == aa)//filter this value which equals *itP
					++itP;
			}
		}
		else if (*itP + *itR < target){
			++itP;
			count = 0;	//rules not satisfied, reset count to 0
		}
		else{
			--itR;
			count = 0;	//rules not satisfied, reset count to 0
		}
	}

	return result;

}

vector<vector<int>> threeSum(vector<int> &num)
{
	/*Assuming the vec &num may contain dulplicates.*/

	vector<vector<int>> triplets;
	triplets.clear();

	if (num.size() <= 2)
		return triplets;

	sort(num.begin(), num.end());

	int a, aa;	//Variable aa to record a's previous value in order to avoid dulplicates
	for (vector<int>::iterator itI = num.begin(); itI != num.end() - 2; ++itI){
		a = *itI;
		if (itI != num.begin()){
			aa = *(itI - 1);
		}
		else{	//assign aa an arbitary value except a
			aa = !a;
		}
		vector<int> bcPairs = twoSum(num, itI + 1, num.end() - 1, -a);
		if (a != aa){
			if (bcPairs.size() >= 2){
				for (int i = 0; i < bcPairs.size(); i += 2){
					triplets.push_back(vector<int> {a, bcPairs[i], bcPairs[i + 1]});
				}
			}
		}
	}
	
	return triplets;
}


