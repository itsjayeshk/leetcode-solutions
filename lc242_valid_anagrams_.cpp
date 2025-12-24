class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> a;
        
        if(s.size() != t.size()){
            return false;
        }
        for(int i = 0;i < s.size();i++){
            if(a.count(s[i])){
                a[s[i]]++;
            }
            else{
                a[s[i]] = 1;
            }
        }
        for(int i = 0;i < t.size();i++){
            if(a.count(t[i])){
                a[t[i]]--;
            }
            if(a[t[i]] == 0){
                a.erase(t[i]);
            }
        }
        if(a.size() == 0){
            return true;
        }
        return false;
        

        
    }
};
