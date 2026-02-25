class Solution {
public:
    int countbits(int x){
        int cnt = 0;
        while(x > 0){
            cnt = cnt + (x % 2);
            x = x / 2;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), [&](int a, int b) {
            int ca = countbits(a);
            int cb = countbits(b);

            if(ca == cb)return a < b;
            return ca < cb;
        });
        return arr;
    }
};
