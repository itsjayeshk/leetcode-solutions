class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ans(numCourses,0);
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
        int completed = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            completed++;
            for(int i = 0;i < adj[node].size();i++){
                int next = adj[node][i];
                ans[next]--;
                if(ans[next] == 0){
                    q.push(next);
                }
            }
        }
        if(completed == numCourses){
            return true;
        }
        return false;
        
        
        
    }
};
