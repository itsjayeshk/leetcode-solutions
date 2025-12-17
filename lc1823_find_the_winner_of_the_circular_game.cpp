class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> players;
        for(int i = 0;i < n;i++){
            players.push_back(i+1);
        }
        int m = 0;
        while(players.size() > 1){
            m = (m + k - 1) % players.size();
            players.erase(players.begin() + m);

        }
        return players[0];
        
    }
};
