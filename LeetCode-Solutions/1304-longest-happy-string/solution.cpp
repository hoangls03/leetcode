#define ii pair<int,char>
#define fi first
#define se second
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<ii> pq;
        if ( a ) pq.push({a,'a'});
        if ( b ) pq.push({b,'b'});
        if ( c ) pq.push({c,'c'});
        string ans = "";
        while ( pq.size() > 1) {
            auto u = pq.top();
            pq.pop();
            if ( ans.size() <= 1 ) {
                ans += u.se;
                u.fi--;
                if ( u.fi ) pq.push(u);
            } else {
                if ( ans[ans.size()-1] == ans[ans.size()-2] && ans[ans.size()-1] == u.se ) {
                    auto v = pq.top();
                    pq.pop();
                    ans += v.se;
                    v.fi--;
                    if ( v.fi ) pq.push(v);
                    pq.push(u);
                }  else {
                    ans += u.se;
                    u.fi--;
                    if ( u.fi ) pq.push(u);
                }
            }
        }
        if ( pq.size() ) {
            auto u = pq.top();
            ans += u.se;
            if ( u.fi >= 2 ) {
                ans += u.se;
            } 
        }
        return ans;
    }
};
