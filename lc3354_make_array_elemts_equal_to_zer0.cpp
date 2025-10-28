#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long prefix = 0;
        int ans = 0;       
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                long long left = prefix;
                long long right = total - prefix - nums[i];
                long long diff = abs(left - right);              
                if(diff == 0){
                    ans = ans + 2; 

                }   
                else if(diff == 1){
                    ans = ans + 1; 
                }
            }
            prefix = prefix + nums[i];
        }
        return ans;
    }
};
