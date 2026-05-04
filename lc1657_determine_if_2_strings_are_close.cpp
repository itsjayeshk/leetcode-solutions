class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return false;
        }
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        if(word1 == word2){
            return true;
        }
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(char c : word1){
            m1[c]++;
        }
        for(char c : word2){
            m2[c]++;
        }
        vector<int> a1;
        vector<int> a2;
        for(auto it : m1){
            a1.push_back(it.second);
        }
        for(auto it : m2){
            a2.push_back(it.second);
        }
        
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());

        return a1 == a2;



        
    }
};
