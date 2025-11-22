class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int currentEnd = 0;
        int maxi = 0;
        for(int i = 0; i < n - 1; ++i){
            maxi = max(maxi, i + nums[i]);

            if(i == currentEnd){
                count++;
                currentEnd = maxi;

                
            }
        }

        return count;
    }
};
