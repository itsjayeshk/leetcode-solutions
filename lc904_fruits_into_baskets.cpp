class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        int initial = 0;
        vector<int> quan;
        unordered_map<int,int> mp;
        for(int i = 0;i < n;i++){
            mp[fruits[i]]++;
            while(mp.size() > 2){
                mp[fruits[initial]]--;
                if(mp[fruits[initial]] == 0){
                    mp.erase(fruits[initial]);

                }
                initial++;
            }
            ans = max(ans,i - initial + 1);
            
        }
        return ans;

        
    }
};
