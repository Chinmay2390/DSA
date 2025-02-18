// gas_station.cpp - Greedy solution for Leetcode 134
#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalTank = 0, currTank = 0, startIndex = 0;

    for (int i = 0; i < gas.size(); ++i) {
        int diff = gas[i] - cost[i];
        totalTank += diff;
        currTank += diff;

        if (currTank < 0) {
            startIndex = i + 1;
            currTank = 0;
        }
    }

    return totalTank >= 0 ? startIndex : -1;
}

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int result = canCompleteCircuit(gas, cost);
    cout << "Start index: " << result << endl;
    return 0;
}
