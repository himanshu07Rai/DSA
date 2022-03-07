class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> mymap;
    list<pair<int,int>> mylist;
    int c = 0,cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mymap.find(key)==mymap.end())
            return -1;
        mylist.splice(mylist.begin(),mylist,mymap[key]);
        return mymap[key]->second;
    }
    
    void put(int key, int value) {
        if(get(key)!=-1)
        {
            mymap[key]->second = value;
            mylist.splice(mylist.begin(),mylist,mymap[key]);
            return;
        }
        if(c==cap)
        {
            int delKey = mylist.back().first;
            mylist.pop_back();
            mymap.erase(delKey);
            c--;
        }
        c++;
        mylist.push_front({key,value});
        mymap[key] = mylist.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */