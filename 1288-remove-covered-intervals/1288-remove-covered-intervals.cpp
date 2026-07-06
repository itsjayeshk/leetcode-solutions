class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        int ans = 0, mx = 0;
        for (auto &i : intervals)
            if (i[1] > mx)
                ans++, mx = i[1];

        return ans;
    }
};