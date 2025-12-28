class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i = 0;i < nums.size();i++){
            m[nums[i]]++;
        } 
        priority_queue<pair<int,int>> p;
        for(auto q : m){
            p.push({q.second,q.first});
        }

        while(k > 0){
            ans.push_back(p.top().second);
            p.pop();
            k--;
        }

        return ans;
    }
};
