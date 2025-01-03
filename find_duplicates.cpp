// find_duplicates.cpp - Find all duplicates in an array
#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0)
            res.push_back(index + 1);
        else
            nums[index] = -nums[index];
    }
    return res;
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> result = findDuplicates(nums);
    cout << "Duplicates: ";
    for (int n : result) cout << n << " ";
    cout << endl;
    return 0;
}
