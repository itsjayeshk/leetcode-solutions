class Solution {
public:
    int rob(vector<int>& nums) {
        int p1 = 0;
        int p2 = 0;
        for(int x : nums){
            int curr = max(p1,p2 + x);
            p2 = p1;
            p1 = curr;



        }
        return p1;
        
    }
};
