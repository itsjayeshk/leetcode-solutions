class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxpro = 0;
        int bestbuy = prices[0];
        int diff;
     

        
        for(int i=1;i<n;i++){
            if(prices[i]<bestbuy){
                bestbuy=prices[i];
            }
            if(prices[i]>bestbuy){
                diff = prices[i] - bestbuy;
                if(diff > maxpro){
                    maxpro = diff;
                }

            }
        }
        return maxpro;
        
    }
};
