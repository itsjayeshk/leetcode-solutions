class Solution {
public:
    int rob(vector<int>& nums) {
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        int p4 = 0;
        if(nums.size() == 1){
            return nums[0];
        }
        for(int i = 0;i < nums.size() - 1;i++){
            int curr = max(p1,p2 + nums[i]);
            p2 = p1;
            p1 = curr;
        }
        for(int i = 1;i < nums.size();i++){
            int curr = max(p3,p4 + nums[i]);
            p4 = p3;
            p3 = curr;
        }
        return max(p1,p3);

        
        
    }
};
