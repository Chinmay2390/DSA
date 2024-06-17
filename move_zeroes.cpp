// move_zeroes.cpp - Shift all zeroes to the end, preserving order
#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0)
            nums[index++] = nums[i];
    }
    while (index < nums.size())
        nums[index++] = 0;
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
