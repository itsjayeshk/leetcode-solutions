class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();
        for(int i = 0;i < n;i++){
            if(target == words[i]){
                int diff = abs(i - startIndex);
                int dist = min(diff,n - diff);
                ans = min(ans,dist);

            }

        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;

        
    }
};
