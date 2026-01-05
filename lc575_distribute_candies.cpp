class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> m;
        for(int i = 0;i < candyType.size();i++){
            m.insert(candyType[i]);
        }
        int maxx = candyType.size()/2;
        int types = m.size();
        if(types < maxx){
            return types;
        }
        return maxx;

        
    }
};
