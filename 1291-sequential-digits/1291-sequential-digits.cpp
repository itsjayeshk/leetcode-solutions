class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> all;
        for(int start = 1;start <= 9;start++){
            int num = start;
            for(int next = start + 1;next <= 9;next++){
                num = num*10 + next;
                all.push_back(num);
            }
        }
        vector<int> ans;
        for(int i = 0;i < all.size();i++){
            if(all[i] >= low && all[i] <= high){
                ans.push_back(all[i]);

            }
        }
        sort(ans.begin(),ans.end());
        return ans;

        
    }
};