class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word; 
        int n = word1.size();
        int m = word2.size();
        int k = 0;
        if(m >= n){
            k = n;
        }else{
            k = m;
        }
        for(int i = 0; i < k; i++){
            word.push_back(word1[i]); 
            word.push_back(word2[i]); 
        }
        if(n > m){
            for(int i = k; i < n; i++){
                word.push_back(word1[i]);
            }
        }
        if(n < m){
            for(int i = k; i < m; i++){
                word.push_back(word2[i]);
            }
        }
        return word; 
    }
};
