class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> ans;

        for(int i = 0;i < nums1.size();i++){
            m[nums1[i]] = 1;   
        }

        for(int i = 0;i < nums2.size();i++){
            if(m.count(nums2[i])){
                ans.push_back(nums2[i]);  
                m.erase(nums2[i]);        
            }
        }
        return ans;
    }
};
