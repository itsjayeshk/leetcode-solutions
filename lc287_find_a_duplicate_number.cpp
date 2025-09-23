class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int num;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j<n;j++){
                if(nums[i] == nums[j]){
                    num = nums[i];
                }
            }

        }
        
        return num;
        
        
    }
};
