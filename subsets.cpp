// subsets.cpp - Generate all possible subsets of a set
#include <iostream>
#include <vector>
using namespace std;

void backtrack(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& result) {
    result.push_back(path);
    for (int i = start; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        backtrack(i + 1, nums, path, result);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    backtrack(0, nums, path, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    for (auto& subset : result) {
        cout << "[";
        for (int n : subset) cout << n << " ";
        cout << "]\n";
    }
    return 0;
}
