class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq1,pq2;

        for(int i = 0; i < n;i++){

            while(!pq2.empty() && pq2.top().first < nums[i]){
                ans[pq2.top().second] = nums[i];
                pq2.pop();
            }

       
            while(!pq1.empty() && pq1.top().first < nums[i]){
                pq2.push(pq1.top());
                pq1.pop();
            }

         
            pq1.push({nums[i],i});
        }

        return ans;
    }
};
