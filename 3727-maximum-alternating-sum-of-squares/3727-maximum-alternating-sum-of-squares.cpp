class Solution {
public:
    
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> order(nums.size());
        
        
        for(int i = 0;i < nums.size();i++){
            long long x = nums[i];
            order[i] = x * x;
        }
        sort(order.begin(),order.end());
        long long sum = 0;
        for(int i = 0;i < order.size()/2;i++){
            sum = sum - order[i];
        }
        for(int i = nums.size()/2;i < nums.size();i++){
            sum = sum + order[i];
        }
        return sum;
        


        
        
    }
};