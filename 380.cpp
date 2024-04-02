class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> mp;
public:

    RandomizedSet() {

    }

    bool search(int val) {
        if (mp.find(val) != mp.end())
            return true;
        return false;
    }

    bool insert(int val) {
        if (search(val)) return false;

        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!search(val)) return false;

        unordered_map<int, int>::iterator i = mp.find(val);
        v[i->second] = v.back();
        v.pop_back();
        mp[v[i->second]] = i->second;
        mp.erase(val);
        return true;

    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
