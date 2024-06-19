// intersection_arrays.cpp - Find unique intersection of two arrays
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s(nums1.begin(), nums1.end());
    unordered_set<int> result;

    for (int num : nums2) {
        if (s.count(num)) result.insert(num);
    }

    return vector<int>(result.begin(), result.end());
}

int main() {
    vector<int> a = {1, 2, 2, 1};
    vector<int> b = {2, 2};

    vector<int> result = intersection(a, b);
    cout << "Intersection: ";
    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}
