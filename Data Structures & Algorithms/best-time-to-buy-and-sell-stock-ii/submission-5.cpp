//  this code baiscally means that adding all the positive changes on the graph this is called the greedy and it is the most simpleset and the efficient tech to apply on the problme so go for ti  , but there is just one constrait of it that we can't use it in a acctual world scenario or in the iterview it might me explicitly asked that don't use the greedy to solve the problem .

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 ;
        for (int i=1 ; i<prices.size();i++){
            if (prices [i-1]<prices[i]) {
                profit+= (prices[i] - prices [ i-1]);

            }
        }
        return profit;
    }
};