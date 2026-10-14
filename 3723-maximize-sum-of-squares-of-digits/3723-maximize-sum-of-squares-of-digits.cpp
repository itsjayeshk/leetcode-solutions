class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int m = num;
        int n = 0;
        string ans = "";
        
        if(sum > 9 * num){
            return "";
        }
        int nines = sum / 9;
        int rem = sum % 9;
        ans = ans + string(nines,'9');
        if(rem > 0){
            ans = ans + char('0' + rem);
        }
        ans =ans + string(num - ans.size(), '0');

        return ans;


        
    }
};