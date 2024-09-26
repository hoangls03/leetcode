#define ii pair<int,int>
#define fi first
#define se second
class MyCalendar {
public:
    bool check( int x, int y, int u, int v ) {
        if ( v <= x || u >= y ) return true;
        return false;  
    }
    vector<ii> vt;
    MyCalendar() {
        vt.clear();
    }
    
    bool book(int start, int end) {
        for ( auto i : vt ) {
            if ( !check(start,end,i.fi,i.se) ) return false;
        }
        vt.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
