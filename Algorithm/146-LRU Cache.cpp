static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if( !mp.count( key ) ) return -1;
        lst.splice( lst.begin(), lst, mp[key] );
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if( mp.count( key ) ) {
            mp[key]->second = value;
            lst.splice( lst.begin(), lst, mp[key] );
        } else {
            lst.push_front( make_pair( key, value ) );
            mp[key] = lst.begin();
            if( lst.size() > cap ) {
                mp.erase( lst.rbegin()->first );
                lst.pop_back();
            }
        }
    }
    
private:
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> lst;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
