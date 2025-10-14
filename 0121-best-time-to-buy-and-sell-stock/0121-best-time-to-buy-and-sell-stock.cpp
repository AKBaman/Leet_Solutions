class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        int profit = 0;

        for(int price : prices){
            if(price < minPrice){
                minPrice = price;
            }

            profit = price - minPrice;

            if(profit > maxProfit){
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};