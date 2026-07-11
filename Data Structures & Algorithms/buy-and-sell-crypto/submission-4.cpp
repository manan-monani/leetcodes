// As we scan through the prices, we keep track of two things:

// The lowest price so far → this is the best day to buy.
// The best profit so far → selling today minus the lowest buy price seen earlier.

// At each price, we imagine selling on that day.
// The profit would be:
// current price – lowest price seen so far

// We then update:

// the maximum profit,
// and the lowest price if we find a cheaper one.


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minBuy = prices[0];

        for (int& sell : prices) {
            maxP = max(maxP, sell - minBuy);
            minBuy = min(minBuy, sell);
        }
        return maxP;
    }
};