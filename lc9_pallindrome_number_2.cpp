class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long long num = x;
        long long revnum = 0;
        while(x != 0){
            int dig = x % 10;
            revnum = revnum*10 + dig;
            x = x/10;
        }
        return revnum == num;
        
    }
};
