//ContainerWithMostWater.cpp

//Greedy algorithm, O(n)
class Solution {
public:
    int maxArea(vector<int> &height) {
        int p = 0, r = height.size() - 1;
        int capacity, maxCapacity = INT_MIN;
        while(p < r){
            capacity = min(height[p], height[r]) * (r - p);
            maxCapacity = capacity > maxCapacity ? capacity : maxCapacity;
            if(height[p] <= height[r])
                ++p;
            else
                --r;
        }
        
        return maxCapacity;
    }
};