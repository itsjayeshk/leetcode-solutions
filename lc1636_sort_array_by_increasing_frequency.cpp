class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;
      
        for(int i = 0;i < nums.size();i++){
            if(m.count(nums[i])){
                m[nums[i]]++;
            }
            else{
                m[nums[i]] = 1;
            }

        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(m[a] != m[b]){
                return m[a] < m[b];  

            }
                 
            return a > b;             
        });

        return nums;
    }
};
