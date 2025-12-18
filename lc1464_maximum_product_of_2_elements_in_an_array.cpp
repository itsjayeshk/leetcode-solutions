class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i = 0;i < nums.size();i++){
            pq.push(nums[i]);

        }
        int product = 1;
        int k = 0;
        while(k < 2){
            product = product * (pq.top() - 1);
            pq.pop();
            k++;
        }
        return product;
        
    }
};
