class LFUCache {
public:
    unordered_map<int,list<vector<int>> ::iterator> mp; // key, Address
    map<int,list<vector<int>>> freq; // counter -> {key,value,counter}
    int cap;
    LFUCache(int capacity) {
        this->cap = capacity;
    }

    void makemostfrequent(int key){
        auto &vec = (*mp[key]);
        int val = vec[1];
        int f = vec[2];
        freq[f].erase(mp[key]);

        if(freq[f].empty()){
            freq.erase(f);
        }
        f++;
        freq[f].push_front({key,val,f});
        mp[key] = freq[f].begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        auto &vec = *mp[key];
        int val = vec[1];
        makemostfrequent(key);
        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(mp.find(key) != mp.end()){
            auto &vec = *mp[key];
            vec[1] = value;
            makemostfrequent(key);
            return;
        }
        else if(mp.size() == cap){
            auto &least_freq_vec = freq.begin()->second;
            int key_to_remove = least_freq_vec.back()[0];
            mp.erase(key_to_remove);
            least_freq_vec.pop_back();
            if(least_freq_vec.empty()){
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front(vector<int> ({key,value,1}));
            mp[key] = freq[1].begin();
        }
        else{
            freq[1].push_front({key,value,1});
            mp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */