class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int st = 0, end = numbers.size() - 1;  
        
        while (end > st) {
            if (numbers[st] + numbers[end] > target) {
                end = end - 1;
            }
            else if (numbers[st] + numbers[end] < target) {
                st = st + 1;
            }
            else { 
                ans.push_back(st + 1); 
                ans.push_back(end+ 1);
                break;
            }
        }
        return ans;
    }
};
