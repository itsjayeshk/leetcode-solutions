class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0;
        int r = 0;
        int u = 0;
        for(char c : moves){
            if(c == 'L'){
                l++;
            }
            else if( c == 'R'){
                r++;
            }
            else{
                u++;
            }
        }
        return (abs(l - r) + u);
    }
};
