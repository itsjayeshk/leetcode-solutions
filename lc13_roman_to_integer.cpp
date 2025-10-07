class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            int curr = 0, next = 0;

            if(s[i] == 'I') curr = 1;
            if(s[i] == 'V') curr = 5;
            if(s[i] == 'X') curr = 10;
            if(s[i] == 'L') curr = 50;
            if(s[i] == 'C') curr = 100;
            if(s[i] == 'D') curr = 500;
            if(s[i] == 'M') curr = 1000;

            if(i + 1 < n) {
                if(s[i + 1] == 'I') next = 1;
                if(s[i + 1] == 'V') next = 5;
                if(s[i + 1] == 'X') next = 10;
                if(s[i + 1] == 'L') next = 50;
                if(s[i + 1] == 'C') next = 100;
                if(s[i + 1] == 'D') next = 500;
                if(s[i + 1] == 'M') next = 1000;
            }

            if(curr < next) sum = sum - curr;
            else sum = sum +  curr;
        }
        return sum;
    }
};
