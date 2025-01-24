// maximum_subarray.cpp - Find max subarray sum using Kadane's Algorithm
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSoFar = nums[0], currMax = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        currMax = max(nums[i], currMax + nums[i]);
        maxSoFar = max(maxSoFar, currMax);
    }
    return maxSoFar;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl;
    return 0;
}

