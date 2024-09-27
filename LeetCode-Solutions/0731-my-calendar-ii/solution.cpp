#define ii pair<int,int> 
#define fi first 
#define se second
class MyCalendarTwo {
public:
    bool check( int x, int y, int u, int v ) {
        if ( v <= x || u >= y ) return true;
        return false;  
    }
    vector<ii> interval, repeat;
    MyCalendarTwo() {
        interval.clear();
        repeat.clear();
    }
    
    bool book(int start, int end) {
        for ( auto i : repeat ) {
            if ( !check(start,end,i.fi,i.se) ) return false;
        }
        for ( auto i : interval ) {
            if ( !check(start,end,i.fi,i.se) ) {
                repeat.push_back({max(i.fi,start),min(i.se,end)});
            }
        }
        interval.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
