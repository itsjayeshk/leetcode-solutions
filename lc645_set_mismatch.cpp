class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int esum = n * (n + 1) / 2; 
        int osum = 0;               

        for (int i = 0; i < n; i++) {
            osum = osum +  nums[i];
        }

        vector<int> freq(n + 1, 0);
        int rep = 0, miss = 0;

        for (int i = 0; i < n; i++) {
            freq[nums[i]] = freq[nums[i]]+ 1;
            if (freq[nums[i]] == 2) rep = nums[i];
        }

       
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 0) miss = i;
        }

        return {rep, miss};
    }
};
