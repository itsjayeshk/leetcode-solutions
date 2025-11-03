class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        vector<int> only1, only2;

        for (int n : s1)
            if (s2.find(n) == s2.end())
                only1.push_back(n);

        for (int n : s2)
            if (s1.find(n) == s1.end())
                only2.push_back(n);

        return {only1, only2};
    }
};
