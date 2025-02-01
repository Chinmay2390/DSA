// subsets_ii.cpp - Generate unique subsets from array with duplicates
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& result) {
    result.push_back(path);
    for (int i = start; i < nums.size(); ++i) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        path.push_back(nums[i]);
        backtrack(i + 1, nums, path, result);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    sort(nums.begin(), nums.end());
    backtrack(0, nums, path, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = subsetsWithDup(nums);

    for (auto& subset : result) {
        cout << "[";
        for (int n : subset) cout << n << " ";
        cout << "]\n";
    }
    return 0;
}
