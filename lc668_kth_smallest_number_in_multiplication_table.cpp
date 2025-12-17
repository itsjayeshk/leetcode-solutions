class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        
        while(low < high){
            long long count = 0;
            int mid = low + (high - low)/2;
            for(int i = 1;i <= m;i++){
                count = count + min(n,mid/i);
            }
            if(count >= k){
                high = mid;

            }
            else{
                low = mid + 1;
            }

        }
        return low;
        
    }
};
