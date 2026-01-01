class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i = 0;i < edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(source);
        visitied[source] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination){
                return true;
            }
            for(int i = 0;i < adj[node].size();i++){
                int next = adj[node][i];
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        return false;
        
    }
};
