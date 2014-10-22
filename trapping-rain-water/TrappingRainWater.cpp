// TrappingRainWater.cpp
//

#include <iostream>
using namespace std;

int trap(int A[], int n);

int main(){

	int *arr = new int[];
	int arrSize = sizeof(arr) / sizeof(int);

	int result = trap(arr, arrSize);

	delete[]arr;
	return 0;
}

const bool ForthToBack = true, BackToForth = false;

void paddingCalcing(int A[], int base, int termanition ,bool isForthToBack, int &capacity)
{
	if (isForthToBack){
		for (int i = base + 1; i < termanition && A[base] >= A[i]; ++i){
			capacity += A[base] - A[i];
			A[i] = A[base];
		}
	}
	else{
		for (int i = base - 1; i > termanition && A[base] >= A[i]; --i){
			capacity += A[base] - A[i];
			A[i] = A[base];
		}
	}
}

int trap(int A[], int n)
{
	/*Here one peak and one valley can either be one point, i.e. A[i];
	or can be one line composing a sequence of consecutive points,
	i.e. A[i], A[i+1], ..., A[j] where A[i] == A[i+1] == ... == A[j]
	Since treating peaks and valleys as eith points or lines will yield
	the same capacity of trapped rain and each point on the line can 
	represent the line, we would choose an arbitary point on the line(
	if it's a line).*/
	int capacity = 0;
	if (n <= 1)
		return capacity;

	int *iPeaks = new int[n];
	int peaksCnt = 0;
	int iPeak, iValley;

	/*Find all the peaks*/
	for (int i = 1; i < n + 1;){
		while (i < n && A[i-1] <= A[i])
			++i;
		if (i == n){
			iPeak = i-1;
			iPeaks[peaksCnt++] = iPeak;
			break;
		}	
		iPeak = i-1;
		iPeaks[peaksCnt++] = iPeak;
		while (i < n && A[i-1] >= A[i])
			++i;
		if (i == n)
			break;
		iValley = i-1;
	}

	/*Pad the gap between peaks,
	calc the capacity, 
	and invalidate some peaks that have been processed*/
	int iPeakA, iPeakB, iPeakC, ii = 0;
	while (ii < peaksCnt){
		if (peaksCnt - 1 == ii){//Only one peak left
			break;
		}
		else if (peaksCnt - 2 == ii){//Two peaks left
			iPeakA = iPeaks[ii]; iPeakB = iPeaks[ii + 1];
			if (A[iPeakA]<= A[iPeakB])
				paddingCalcing(A, iPeakA, iPeakB, ForthToBack, capacity);
			else
				paddingCalcing(A, iPeakB, iPeakA, BackToForth, capacity);
			break;
		}
		else{//Three or more peaks left
			iPeakA = iPeaks[ii]; iPeakB = iPeaks[ii + 1]; iPeakC = iPeaks[ii + 2];
			if (A[iPeakA] <= A[iPeakB]){
				paddingCalcing(A, iPeakA, iPeakB, ForthToBack, capacity);
				if (A[iPeakB] <= A[iPeakC]){// A <= B <= C
					paddingCalcing(A, iPeakB, iPeakC, ForthToBack, capacity);
					ii += 2;
				}
				else{// A <= B > C
					paddingCalcing(A, iPeakC, iPeakB, BackToForth, capacity);
					ii += 2;
					iPeaks[ii] = iPeakB;
				}
			}
			else{
				paddingCalcing(A, iPeakB, iPeakA, BackToForth, capacity);
				if (A[iPeakB] < A[iPeakC]){// A > B < C
					paddingCalcing(A, iPeakB, iPeakC, ForthToBack, capacity);
					ii += 1;
					iPeaks[ii] = iPeakA;
				}
				else{// A > B >= C
					paddingCalcing(A, iPeakC, iPeakB, BackToForth, capacity);
					ii += 2;
					iPeaks[ii] = iPeakA;
				}
			}
		}
	}

	delete[]iPeaks;
	return capacity;
}

