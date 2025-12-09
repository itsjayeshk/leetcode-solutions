class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long count = 0;
        for(int i = 0;i < nums.size() - 1;i++){
            int target = 2*nums[i];
            int left = 0;
            int right = 0;

            for(int j = 0;j < i;j++){
                if(nums[j] == target){
                    left++;

                }
            }
            for(int k = i + 1;k < nums.size();k++){
                if(nums[k] == target){
                    right++;
                }
            }
            count = count + (left*right);


        }
        return count;
        
    }
};
