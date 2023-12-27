#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }

    vector<int> firstTransaction(n, 0);
    vector<int> secondTransaction(n, 0);

    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrice = min(minPrice, prices[i]);
        firstTransaction[i] = max(firstTransaction[i - 1], prices[i] - minPrice);
    }

    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = max(maxPrice, prices[i]);
        secondTransaction[i] = max(secondTransaction[i + 1], maxPrice - prices[i]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxProfit = max(maxProfit, firstTransaction[i] + secondTransaction[i]);
    }

    return maxProfit;
}

int main() {

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int result = maxProfit(prices);

    cout << "Maximum profit with two transactions: " << result << endl;

    return 0;
}