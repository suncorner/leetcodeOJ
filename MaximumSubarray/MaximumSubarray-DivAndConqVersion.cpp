//MaximumSubarray-DivAndConqVersion.cpp

class Solution {
public:
	int maxLeftSegment(int A[], int p, int r)
	{
		int sum = 0, maxSum = INT_MIN;
        for(int i = r; i >= p; --i){
        	sum += A[i];
        	maxSum = maxSum < sum ? sum : maxSum;
        }
        return maxSum > 0 ? maxSum : 0;
	}
	int maxRightSegment(int A[], int p, int r)
	{
		int sum = 0, maxSum = INT_MIN;
        for(int i = p; i <= r; ++i){
        	sum += A[i];
        	maxSum = maxSum < sum ? sum : maxSum;
        }
        return maxSum > 0 ? maxSum : 0;
	}
	int maxSubArr(int A[], int p, int r)
	{
		if(n == 0)
            return INT_MIN;
            
       	int p = 0, r = n - 1;
        int mid = (p + r) / 2;
        int midSegmentSum = maxLeftSegment(A, mid, p) + maxRightSegment(A, mid, r) - A[mid];
        int leftSum = maxSubArr(A, p, mid);
        int rightSum = maxSubArr(A, mid, r); 
        int maxSum = leftSum > rightSum ? leftSum : rightSum;
        maxSum = midSegmentSum > maxSum ? midSegmentSum : maxSum;
        
        return maxSum;
	}
    int maxSubArray(int A[], int n)
    {
        return maxSubArr(A, 0, n - 1);
    }
};