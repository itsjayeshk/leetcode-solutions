class Solution {
public:
    bool dfs(vector<int>& arr,int idx,vector<bool>& vis){
        if(idx < 0 || idx >= arr.size()){
            return false;
        }
        if(vis[idx]){
            return false;
        }
        if(arr[idx] == 0){
            return true;
        }
        vis[idx] = true;
        int jump = arr[idx];
        return dfs(arr,idx + jump,vis) || dfs(arr,idx - jump,vis);

    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(),false);

        return dfs(arr,start,vis);
        
    }
};
