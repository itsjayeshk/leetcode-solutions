class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonze = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[nonze] = nums[i];
                nonze++;
            }
        }
        for (int i = nonze; i < n; i++) {
            nums[i] = 0;
        }
    }
};
