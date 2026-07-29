class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        string ans = "";
        do {
            int hour = arr[0] * 10 + arr[1];
            int minutes = arr[2] * 10 + arr[3];
            if(hour < 24 && minutes < 60){
                string time = "";
                time = time + char(arr[0] + '0');
                time = time + char(arr[1] + '0');
                time = time + ":";
                time = time + char(arr[2] + '0');
                time = time + char(arr[3] + '0');

                if(time > ans){
                    ans = time;
                }

            }
        } while(next_permutation(arr.begin(),arr.end()));
        return ans;
        
    }
};