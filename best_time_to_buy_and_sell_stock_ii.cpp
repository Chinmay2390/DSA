// best_time_to_buy_and_sell_stock_ii.cpp - Max profit with multiple transactions
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    }
    return profit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
    return 0;
}
