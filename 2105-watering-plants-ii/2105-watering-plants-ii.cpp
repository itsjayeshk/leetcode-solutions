class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans = 0;

        int i = 0;
        int j = plants.size() - 1;

        int ca = capacityA;
        int cb = capacityB;

        while (i < j) {

            if (plants[i] <= ca) {
                ca -= plants[i];
            } else {
                ans++;
                ca = capacityA - plants[i];
            }

            if (plants[j] <= cb) {
                cb -= plants[j];
            } else {
                ans++;
                cb = capacityB - plants[j];
            }

            i++;
            j--;
        }

        if (i == j) {
            if (max(ca, cb) < plants[i]) {
                ans++;
            }
        }

        return ans;
    }
};