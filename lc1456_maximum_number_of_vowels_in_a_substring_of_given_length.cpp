class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    int maxVowels(string s, int k) {
        int counter = 0;

        
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) counter++;
        }

        int maxi = counter;

        for(int j = k; j < s.size(); j++){
            if(isVowel(s[j])) counter++;
            if(isVowel(s[j - k])) counter--;

            maxi = max(maxi, counter);
        }

        return maxi;
    }
};
