class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int left = 0;
        int right = n - 1;
        int score = 0;
        int ans = 0;
        while (left <= right) {
            if (power >= tokens[left]) {
                score++;
                power = power - tokens[left];
                left++;
                ans = max(ans, score);
            } else if (score > 0) {
                power = power + tokens[right];
                right--;
                score--;
            } else {
                break;
            }
        }
        return ans;
    }
};