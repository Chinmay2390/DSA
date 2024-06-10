// binary_search.cpp - Classic binary search on sorted array
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 7;

    int index = binarySearch(nums, target);
    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
