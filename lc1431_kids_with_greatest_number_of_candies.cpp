class Solution {
public:
    bool ismax(int count,vector<int>& candies){
        for(int i = 0; i < candies.size();i++){
            if(count < candies[i]){
                return false;
            }
        }
        return true;
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        for(int i = 0; i < candies.size();i++){
            int count = 0;
            count = candies[i] + extraCandies;
            if(ismax(count,candies)){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
            
        }
        return ans;

        
    }
};
