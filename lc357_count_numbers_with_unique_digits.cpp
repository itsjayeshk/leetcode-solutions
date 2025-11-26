class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0){
            return 1;   
        }   
        if(n > 10){
            n = 10; 
        }       
        int ans = 10;       
        int unique = 9;      
        int available = 9;         

        for(int i = 2;i <= n;i++){
            unique = unique * available;
            ans = ans + unique;
            available--;
        }

        return ans;
    }
};
