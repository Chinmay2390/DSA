// partition_equal_subset_sum.cpp - Can array be partitioned into two equal subsets?
#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int num : nums) total += num;
    if (total % 2 != 0) return false;

    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int i = target; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }

    return dp[target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << (canPartition(nums) ? "Can Partition" : "Cannot Partition") << endl;
    return 0;
}
