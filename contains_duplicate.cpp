// contains_duplicate.cpp - Check for duplicates using a set
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 1};
    cout << (containsDuplicate(nums) ? "Duplicate found" : "No duplicates") << endl;
    return 0;
}
