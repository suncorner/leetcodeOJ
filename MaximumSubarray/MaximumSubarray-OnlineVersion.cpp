//MaximumSubarray-OnlineVersion.cpp

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0)
            return INT_MIN;
            
        int sum = 0, maxSum = INT_MIN;
        for(int i = 0;i < n; ++i){
            sum += A[i];
            maxSum = maxSum < sum ? sum : maxSum;
            sum = sum >= 0 ? sum : 0;
        }
        
        return maxSum;
    }
};