class Solution {
public:
    vector<int> path;
    vector<vector<int>> paths;
    void helper(int u,vector<vector<int>>& graph){
        path.push_back(u);
        if(u == graph.size() - 1){
            paths.push_back(path);
        }
        else{
            for(int v : graph[u]){
                helper(v,graph);
            }
        }
        path.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        helper(0,graph);
        return paths;
        
    }
};
