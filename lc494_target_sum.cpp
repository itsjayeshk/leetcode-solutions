class Solution {
public:
    int count = 0;
    void expressions(vector<int>& nums,int target,int index,int sum){
        if(index == nums.size()){
            if(sum == target){
                count++;
            }
            return;
        }
        expressions(nums,target,index + 1,sum + nums[index]);
        expressions(nums,target,index + 1,sum - nums[index]);




    }
    int findTargetSumWays(vector<int>& nums, int target) {
        expressions(nums,target,0,0);
        return count;
        
    }
};
