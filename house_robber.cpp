// house_robber.cpp - Max money without robbing adjacent houses
#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int prev = 0, curr = 0;
    for (int num : nums) {
        int temp = curr;
        curr = max(prev + num, curr);
        prev = temp;
    }
    return curr;
}

int main() {
    vector<int> houses = {2, 7, 9, 3, 1};
    cout << "Max money robbed: " << rob(houses) << endl;
    return 0;
}
