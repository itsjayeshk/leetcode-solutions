class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitude;
        altitude.push_back(0);
        for(int i = 0;i < gain.size();i++){
            altitude.push_back(gain[i] + altitude[i]);           
        }
        return *max_element(altitude.begin(),altitude.end());
    }
};
