class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxArea = 0; 

        while(right > left) {
            int width = right - left;
            int ht = min(height[left], height[right]);
            maxArea = max(maxArea, width * ht);

            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;  
    }
};
