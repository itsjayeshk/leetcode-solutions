class Solution {
public:
    bool isObstacle(int x, int y, vector<vector<int>>& obstacles) {
        for(auto &o : obstacles){
            if (o[0] == x && o[1] == y) return true;
        }
        return false;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int d = 0;
        int maxDist = 0;
        vector<pair<int,int>> dir = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };

        for(int cmd : commands){
            if(cmd == -1){
                d = (d + 1) % 4;
            }
            else if(cmd == -2){
                d = (d + 3) % 4;
            }
            else{
                for(int i = 0; i < cmd; i++){
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;
                    if (isObstacle(nx, ny, obstacles)) break;
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};
