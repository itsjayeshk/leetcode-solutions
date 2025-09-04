class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mj = n / 2;

        for (int i = 0; i < n; i++) {
            int freq = 0;  
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    freq++;
                }
            }
            if (freq > mj) {
                return nums[i];
            }
        }
        return -1; 
    }
};
