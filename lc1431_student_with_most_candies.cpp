class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n);
        int maxCand = *max_element(candies.begin(), candies.end());
        int x = extraCandies;
        for(int i = 0;i < n;i++){
            int total = candies[i] + x;
            if(total >= maxCand){
                ans[i] = true;

            }
            else{
                ans[i] = false;
            }
        }
        return ans;

        
    }
};
