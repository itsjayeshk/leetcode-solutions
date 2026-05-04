class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0;i < arr.size();i++){
            if(mp[arr[i]] == 0){
                mp[arr[i]] = 1;
            }else{
                mp[arr[i]]++;
            }

        }
        vector<int> occur;
        for(auto it : mp){
            occur.push_back(it.second);
        }

        sort(occur.begin(),occur.end());
        for(int j = 1;j < occur.size();j++){
            if(occur[j] == occur[j-1]){
                return false;
            }
        }
        return true;
        

        
    }
};
