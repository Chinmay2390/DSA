// remove_duplicates.cpp - Remove duplicates in-place from sorted array
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int index = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[index++] = nums[i];
        }
    }

    return index;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};
    int len = removeDuplicates(nums);

    cout << "After removing duplicates: ";
    for (int i = 0; i < len; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}
