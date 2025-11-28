class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maximum = INT_MIN;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n < 2){
            return 0;
        }
        for(int i = 0;i < n - 1;i++){
            int diff = nums[i+1] - nums[i];
            
            if(diff > maximum){
                maximum = diff;

            }
        }
        return maximum;
        
    }
};
