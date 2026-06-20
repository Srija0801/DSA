class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        int maxPrice=0;
        int profit=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            minPrice=min(minPrice,prices[i]);
            profit=max(profit,prices[i]-minPrice);
        }
        return profit;
    }
};
