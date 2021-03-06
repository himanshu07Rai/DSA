class MyHashMap {
    private:
    const int my_size=10000;
    vector<list<pair<int,int>>>hash;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hash.resize(my_size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto&Mylist=hash[key%my_size];
        for(auto&Mypair:Mylist){
            if(Mypair.first==key){
                Mypair.second=value;
                return;
            }
        }
        Mylist.push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto&Mylist=hash[key%my_size];
        for(auto&Mypair:Mylist){
            if(Mypair.first==key){
                return Mypair.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto&Mylist=hash[key%my_size];
        for(auto&Mypair:Mylist){
            if(Mypair.first==key){
                Mylist.remove(Mypair);
                return;
            }
        }
    }
};