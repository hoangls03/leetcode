#define ii pair<long long,long long>
#define fi first
#define se second
class Solution {
public:
    static bool cmp( ii a, ii b ) {
        long long u = a.se - a.fi;
        long long v = a.se * a.se + a.se;
        long long x = b.se - b.fi;
        long long y = b.se * b.se + b.se;
        return ( u*y < x*v );
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<ii,vector<ii>,decltype(&cmp)> pq(cmp);
        for ( auto e : classes ) {
            pq.push({e[0],e[1]});
        }
        while ( extraStudents ) {
            auto u = pq.top();
            pq.pop();
            u.fi += 1;
            u.se += 1;
            pq.push(u);
            extraStudents--;
        }
        double ans = 0;
        while ( pq.size() ) {
            auto u = pq.top();
            double x = u.fi;
            double y = u.se;
            ans += x/y;
            pq.pop();
        }
        long long n = classes.size();
        ans /= n;
        return ans;
    }
};
