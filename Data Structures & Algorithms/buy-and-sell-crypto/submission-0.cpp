// so in this solution for the best solution we can do that in the array first we find the smallest element and then after that element in the following element we will choose the highest so that we can get he maximum amount of the profit .
// so we just only have to return the max profit so this is more easier . we can tackel this thing with the 
// help of the hashmaps . 
//  here there are two approaches are given for the optimal solution , one is the two pointer thing and the another one is all time most fav DP.
// we will go through the both the approach because still i have not learn the dp approach . so we have to learn that also and the two pointe rthing is also very interesting so we have to look after that thing also . 

// 2. Two Pointers
// Intuition
// We want to buy at a low price and sell at a higher price that comes after it.
// Using two pointers helps us track this efficiently:

// l is the buy day (looking for the lowest price)
// r is the sell day (looking for a higher price)
// If the price at r is higher than at l, we can make a profit — so we update the maximum.
// If the price at r is lower, then r becomes the new l because a cheaper buying price is always better.

// By moving the pointers this way, we scan the list once and always keep the best buying opportunity.

// Algorithm
// Set two pointers:
// l = 0 (buy day)
// r = 1 (sell day)
// maxP = 0 to track maximum profit
// While r is within the array:
// If prices[r] > prices[l], compute the profit and update maxP.
// Otherwise, move l to r (we found a cheaper buy price).
// Move r to the next day.
// Return maxP at the end.

// two pointer code 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxP = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            } else {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};

// 3. Dynamic Programming
// Intuition
// As we scan through the prices, we keep track of two things:

// The lowest price so far → this is the best day to buy.
// The best profit so far → selling today minus the lowest buy price seen earlier.
// At each price, we imagine selling on that day.
// The profit would be:
// current price – lowest price seen so far

// We then update:

// the maximum profit,
// and the lowest price if we find a cheaper one.
// This way, we make the optimal buy–sell decision in one simple pass.

// Algorithm
// Initialize:
// minBuy as the first price
// maxP = 0 for the best profit
// Loop through each price sell:
// Update maxP with sell - minBuy.
// Update minBuy if we find a smaller price.
// Return maxP after scanning all days.

// dp code 

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxP = 0;
//         int minBuy = prices[0];

//         for (int& sell : prices) {
//             maxP = max(maxP, sell - minBuy);
//             minBuy = min(minBuy, sell);
//         }
//         return maxP;
//     }
// };


// in both the case time is N and the space is 1 so we have tackeled both the things . . 