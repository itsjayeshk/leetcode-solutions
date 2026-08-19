class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int n : nums){
            mp[n]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto q : mp){
            pq.push({q.second,q.first});

        }
        vector<int> ans;
        while(k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;

        }
        return ans;

        
    }
};