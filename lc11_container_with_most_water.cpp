class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int width = j - i;
                int length = min(height[i], height[j]);  // ✅ correct
                int area = width * length;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
