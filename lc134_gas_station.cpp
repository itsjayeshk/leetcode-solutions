class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int currgas = 0;
        int totalgas = 0;
        int n = gas.size();
        for(int i = 0;i < n;i++){
            int diff = gas[i] - cost[i];
            currgas = currgas + diff;
            totalgas = totalgas + diff;

            if(currgas < 0){
                start = i + 1;
                currgas = 0;
            }
        }
        if(totalgas >= 0){
            return start;
        }
        return -1;

        
    }
};
