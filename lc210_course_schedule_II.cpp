class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans(numCourses,0);
        vector<int> ans1;
        vector<int> empty;
        vector<vector<int>> adj(numCourses);
        for(int i = 0;i < prerequisites.size();i++){
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            adj[pre].push_back(course);
            ans[course]++;

        }
        queue<int> q;
        for(int i = 0;i < numCourses;i++){
            if(ans[i] == 0){
                q.push(i);
            }
        }
       
        while(!q.empty()){
            int node = q.front();
            ans1.push_back(node);
            q.pop();
            
            for(int i = 0;i < adj[node].size();i++){
                int next = adj[node][i];
                ans[next]--;
                if(ans[next] == 0){
                    q.push(next);
                }
            }



        
        }
        if(ans1.size() == numCourses){
            return ans1;
        }
        return empty;
        
        
    }
};
