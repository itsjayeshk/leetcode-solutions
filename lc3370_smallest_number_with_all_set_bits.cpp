class Solution {
public:
    int powof2(int n){
        int ans = 1;
        while(ans < n){
            ans = ans * 2;
        }
        return ans;

    }
    bool isPowerOfTwo(int n){
        if(n <= 0){
            return false;
        }
        if((n & (n - 1)) == 0){
            return true;
        }
        return false;
        
    }
    int smallestNumber(int n) {
        if(n == 1){
            return true;
        }
        if(isPowerOfTwo(n) == true){
            return (n*2)-1;
        }
        int temp = powof2(n);
        int fans = temp - 1;
        return fans;
        
    }
};
