class Solution {
public:
    int sumOfDigits(int n){
        int sum = 0;
        while(n != 0){
            sum = sum + (n % 10);
            n = n / 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            int x = sumOfDigits(nums[i]);
            if(x == i){
                return i;
            }
        }
        return -1;
        
    }
};