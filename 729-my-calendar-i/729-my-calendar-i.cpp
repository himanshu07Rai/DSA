class MyCalendar {
    vector<pair<int,int>>myCalendar;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto b:myCalendar)
        {
            if(start<b.second && b.first<end)
                return false;
        }
        myCalendar.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */