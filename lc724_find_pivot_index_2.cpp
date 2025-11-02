class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tsum = 0;
        for(int num : nums){
            tsum = tsum + num; 
        }
        int lsum = 0;
        for(int i = 0; i < nums.size(); i++){
            int rsum = tsum - lsum - nums[i];
            if(lsum == rsum){
                return i; 
            }
            lsum = lsum + nums[i]; 
        }
        return -1; 
    }
};
