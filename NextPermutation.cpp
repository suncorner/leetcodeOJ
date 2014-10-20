// NextPermutation.cpp
//

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &num);

typedef vector<int>::iterator VIt;

void printV(vector<int> &num){
	for (int i = 0; i < num.size(); ++i){
		cout << num[i] << ' ';
	}
	cout << endl;
}

int main(){

    int arr[] = { 4, 2, 0, 2, 3, 2, 0};
	int arrSize = sizeof(arr) / sizeof(int);
	int elem = 1;

	vector<int> vi(arr, arr + arrSize);
	VIt i = vi.begin() + 3, j = vi.end() - 1;

	printV(vi);
	nextPermutation(vi); 
	printV(vi);

	return 0;
}

void mySwap(vector<int> &num, VIt x, VIt y)
{
	int tmp = *y;
	*y = *x;
	*x = tmp;
}

void reverseV(vector<int> &num, VIt p, VIt r)
{
	if (r - p < 1)
		return;

	VIt i = p, j = r;
	for (; i < j; ++i, --j){
		mySwap(num, i, j);
	}
}

VIt myBSearch(VIt p, VIt r, int elem)
{
    VIt i = p;
    if(r - p < 10){
        while(i <= r && *i <= elem)
            ++i;
        return i;
    }

    VIt mid = p + (r - p) / 2;
    if(*mid <= elem){
        return myBSearch(mid, r, elem);
    }
    else{
        return myBSearch(p, mid, elem);
    }
}

void nextPermutation(vector<int> &num)
{
	if (num.size() <= 1)
		return;

	VIt i, j;
	i = num.end() - 1;
	while (i > num.begin()){
		j = i - 1;
		bool flagJ = false;
		while (j >= num.begin()){
			if (flagJ)
				break;

			if (*j < *(j + 1)){
				/*With [j+1, num.end()-1] already in not ascending order,
				we reverse it at first.*/
				reverseV(num, j + 1, num.end() - 1);
				/*Just need to swap *j and the first elem bigger than *j.*/
				VIt lb = myBSearch(j + 1, num.end() - 1, *j);
				mySwap(num, j, lb);

				goto L1;
			}
			if (j == num.begin())
				flagJ = true;
			else
				--j;
		}
		--i;
	}

	/*This permutation is already the possible biggest, so reverse it.*/
	i = num.begin(); j = num.end() - 1;
	reverseV(num, i, j);

L1:
	return;

}

bool myCmp(const int &, const int &y)
{
	return x <= y;
}

/*Version 2. Overload Func Cmp of std::lower_bond() which doesn't work for some GCC.*/
void nextPermutation_v2(vector<int> &num)
{
	if (num.size() <= 1)
		return;

	VIt i, j;
	i = num.end() - 1;
	while (i > num.begin()){
		j = i - 1;
		bool flagJ = false;
		while (j >= num.begin()){
			if (flagJ)
				break;

			if (*j < *(j + 1)){
				/*With [j+1, num.end()-1] already in not ascending order,
				we reverse it at first.*/
				printV(num);
				reverseV(num, j + 1, num.end() - 1);
				printV(num);
				/*Just need to swap *j and the first elem bigger than *j.*/
				VIt lb = lower_bound(j + 1, num.end() - 1, *j, myCmp);
				mySwap(num, j, lb);

				goto L1;
			}
			if (j == num.begin())
				flagJ = true;
			else
				--j;
		}
		--i;
	}

	/*This permutation is already the possible biggest, so reverse it.*/
	i = num.begin(); j = num.end() - 1;
	reverseV(num, i, j);

L1:
	return;

}
