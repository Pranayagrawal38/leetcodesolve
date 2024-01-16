class RandomizedSet {
public:

    vector<int> s;
    unordered_map<int , int> m;
    int i;
    RandomizedSet() {i = 0;}

    bool insert(int val) {
        if (m.find(val) == m.end()) {
            s.push_back(val);
            m[val] = i++; 
            return true;
        } else
            return false;
    }

    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        } 
        else{
            int x = s.back();
            s[m[val]] = x;
            s.pop_back();
            m[x] = m[val];
            m.erase(val);
            i--;
            return true;
        }
    }
    int getRandom() {

        return s[rand()%s.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */