class LRUCache {
public:
    list<int>dll;
    map<int,pair<list<int>::iterator,int>>mp;
    int n;
    LRUCache(int capacity){
    n=capacity;
    }
    void makelru(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    int get(int key) {
    if(mp.find(key)==mp.end())
    return -1;
    makelru(key);
    return mp[key].second;
    }
    void put(int key, int value) {
    if(mp.find(key)!=mp.end())
    {
       mp[key].second=value;
       makelru(key);
    }    
    else 
    {
        dll.push_front(key);
        mp[key]={dll.begin(),value};
        n--;
    }
    if(n<0)
    {
        int keytodel=dll.back();
        mp.erase(keytodel);
        dll.pop_back();
        n++;
    }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */