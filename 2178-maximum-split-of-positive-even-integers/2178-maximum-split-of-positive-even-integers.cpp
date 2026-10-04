
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;

        if (finalSum % 2 != 0) return ans;

        long long sum = 0;

        for (long long i = 2; sum + i <= finalSum; i += 2) {
            ans.push_back(i);
            sum += i;
        }

        if (!ans.empty() && sum < finalSum) {
            ans.back() += finalSum - sum;
        }

        return ans;
    }
};
