// house_robber_ii.cpp - Rob houses in a circular neighborhood
#include <iostream>
#include <vector>
using namespace std;

int robLinear(vector<int>& nums, int start, int end) {
    int prev = 0, curr = 0;
    for (int i = start; i <= end; ++i) {
        int temp = curr;
        curr = max(prev + nums[i], curr);
        prev = temp;
    }
    return curr;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
}

int main() {
    vector<int> houses = {2, 3, 2};
    cout << "Max money robbed (circular): " << rob(houses) << endl;
    return 0;
}
