class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int end = 0;
        int m = 0;
        for(int i = 0;i < n - 1;i++){
            m = max(m,i + nums[i]);

            if(i == end){
                cnt++;
                end = m;

                
            }
        }

        return cnt;
    }
};
