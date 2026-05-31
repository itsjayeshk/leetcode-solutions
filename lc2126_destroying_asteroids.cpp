class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long cmass = mass;
        for(int i = 0;i < asteroids.size();i++){
            if(cmass < asteroids[i]){
                return false;
            }
            cmass = cmass + asteroids[i];
        }
        return true;
    }
};
