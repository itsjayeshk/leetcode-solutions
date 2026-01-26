class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> tempans;
        sort(arr.begin(),arr.end());
        int mini = INT_MAX;
        for(int i = 0;i < n - 1;i++){
            int j = i + 1;
            if(mini > (arr[j] - arr[i])){
                mini = arr[j] - arr[i];
            }
        }
        for(int i = 0;i < n - 1;i++){
            int j = i + 1;
            if(mini == (arr[j] - arr[i])){
                tempans.push_back(arr[i]);
                tempans.push_back(arr[j]);
                ans.push_back(tempans);
                tempans.pop_back();
                tempans.pop_back();
            }
        }
        return ans;

        
    }
};
