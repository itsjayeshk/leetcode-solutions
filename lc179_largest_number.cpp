class Solution {
public:
    static bool cmp(string a,string b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for (int x : nums) {
            ans.push_back(to_string(x));
        }
        sort(ans.begin(), ans.end(),cmp);
        if (ans[0] == "0") {
            return "0";
        }
        string fans = "";
        for (string c : ans) {
            fans = fans + c;
        }

        return fans;
    }
};
