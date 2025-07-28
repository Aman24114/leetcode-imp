class LFUCache {
public:
    int cap;
    int size;
    unordered_map<int, list<vector<int>>::iterator> mp;
    map<int, list<vector<int>>> freq;

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    void f(int key) {
        auto &vec = *(mp[key]);
        int value = vec[1];
        int f = vec[2];
        freq[f].erase(mp[key]);
        if (freq[f].empty()) {
            freq.erase(f);
        }
        f++;
        freq[f].push_front({key, value, f});
        mp[key] = freq[f].begin();
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        int value = (*(mp[key]))[1];
        f(key);
        return value;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        if (mp.find(key) != mp.end()) {
            auto &vec = *(mp[key]);
            vec[1] = value;
            f(key);
        } else {
            if (size < cap) {
                size++;
            } else {
                auto &list = freq.begin()->second;
                int keyd = list.back()[0];
                list.pop_back();
                if (list.empty()) {
                    freq.erase(freq.begin()->first);
                }
                mp.erase(keyd);
            }
            freq[1].push_front({key, value, 1});
            mp[key] = freq[1].begin();
        }
    }
};