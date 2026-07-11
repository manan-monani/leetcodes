class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int minbuy=prices[0];

        for (int& sell : prices){
            maxprofit = max(maxprofit , sell - minbuy);
            minbuy = min (minbuy , sell );

        }
        return maxprofit;
    }
};
