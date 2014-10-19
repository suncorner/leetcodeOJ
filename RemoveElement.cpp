// RemoveElement.cpp
//

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int removeElement(int A[], int n, int elem);

int main(){

	int arr[] = { 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 5, 1 ,1};
	int arrSize = sizeof(arr) / sizeof(int);
	int elem = 1;

	int cnt = removeElement(arr, arrSize, elem);

	return 0;
}

void mySwap(int *px, int *py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

int searchBackToForth_Swap(int A[], int r, int elem, int &elemCnt)
{
	int nextR = -1;	//start index for next round search&swap, i.e. for this function's next being called
	int i = r, p, q;

	while (i >= 0 && A[i] == elem){
		--i; ++elemCnt;
	}
	q = i; //first "NotEqualTO" element index searching from back to forth

	nextR = q > 0 ? q - 1 : -1;
	int j = q - 1;
	while (j >= 0 && A[j] != elem){
		--j;
	}

	if (j >= 0){
		p = j;	//first "EqualTo" element index searching from back to forth
		++elemCnt;
		mySwap(A + p, A + q);
	}
	else{
		nextR = -1;
	}
	
	return nextR;
}

int removeElement(int A[], int n, int elem)
{
	int elemCnt = 0;
	int index = n - 1;

	do{
		index = searchBackToForth_Swap(A, index, elem, elemCnt);
	} while (index >= 0);
	
	return n - elemCnt;
}