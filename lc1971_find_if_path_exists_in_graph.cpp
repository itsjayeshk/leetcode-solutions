class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i = 0;i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        return dfs(source,destination,adj,visited);


        
    }
    bool dfs(int node,int dest,vector<vector<int>>& adj,vector<bool>& visited){
        if(node == dest){
            return true;
        }
        visited[node] = true;
        for(int i = 0;i < adj[node].size();i++){
            int next = adj[node][i];
            if(!visited[next]){
                if(dfs(next,dest,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
