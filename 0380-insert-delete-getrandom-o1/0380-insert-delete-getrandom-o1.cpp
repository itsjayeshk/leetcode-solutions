class RandomizedSet {
private:
    vector<int> random;
    unordered_map<int, int> mp;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }

        mp[val] = random.size();
        random.push_back(val);

        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }

        int index = mp[val];
        int last = random.back();

        random[index] = last;
        mp[last] = index;

        random.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() { return random[rand() % random.size()]; }
};