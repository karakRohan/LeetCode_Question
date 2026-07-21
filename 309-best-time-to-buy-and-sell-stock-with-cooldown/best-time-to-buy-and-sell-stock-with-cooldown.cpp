class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold= -prices[0], sold=0, rest=0;
        for (int i=1; i<prices.size(); i++) {
            int oldHold = hold, oldSold = sold, oldRest = rest;
            hold = max(oldHold, oldRest - prices[i]);
            sold = oldHold + prices[i];
            rest = max(oldRest, oldSold);
        }
        return max(sold, rest);
    }
};