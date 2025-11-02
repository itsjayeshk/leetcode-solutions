class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int i = 0; 
        while(i < n){
            int lsum = 0;
            int rsum = 0;
            for(int j = 0; j < i; j++){
                lsum = lsum + nums[j];
            }
            for(int k = i + 1; k < n; k++){
                rsum = rsum + nums[k];
            }
            if(lsum == rsum){
                return i;
            }
            i = i + 1;
        }
        return -1;
    }
};
