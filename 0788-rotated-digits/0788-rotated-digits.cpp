class Solution {
public:
    bool isGood(int x){
        vector<int> digits;
        while(x > 0){
            int m = x % 10;
            x = x / 10;
            digits.push_back(m);
        }
        bool checker = false;
        for(int a : digits){
            if(a == 2 || a == 5 || a == 6 || a == 9){
                checker = true;
            }
            if(a == 3 || a == 4 || a == 7){
                return false;
            }
        }
        return checker;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1;i <= n;i++){
            bool isgood = false;
            isgood = isGood(i);
            if(isgood == true){
                ans++;
            }
            else{
                continue;
            }
        }
        return ans;
        
    }
};