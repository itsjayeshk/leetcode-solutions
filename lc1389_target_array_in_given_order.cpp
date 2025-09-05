class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> target;
        target.reserve(n);
        for (int i = 0; i < n; i++) {
            target.push_back(0); 
            for (int j = n - 1; j > index[i]; j--) {
                target[j] = target[j - 1]; 
            }
            target[index[i]] = nums[i]; 
        }
        return target;
    }
};
