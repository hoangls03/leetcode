#define ii pair<int,int>
#define fi first
#define se second
const int oo = 1e10;
class Solution {
public:
    int seg[400005];
    void update( int id, int l, int r, int u, int val) {
        if ( u < l || r < u ) {
            return ;
        }
        if ( l == r ) {
            seg[id] = val;
            return ;
        }
        int mid = ( l + r ) >> 1;
        update(id * 2,l,mid,u,val);
        update(id * 2 + 1,mid + 1,r,u,val);
        seg[id] = min(seg[id*2],seg[id*2 + 1]);
    }
    int get( int id, int l, int r, int u, int v ) {
        if ( v < l || r < u ) {
            return oo;
        }
        if ( u <= l && r <= v ) {
            return seg[id];
        }
        int mid = ( l + r ) >> 1;
        return min(get(id*2,l,mid,u,v),get(id*2 + 1,mid + 1,r,u,v));
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        for ( int i = 0 ; i <= 4*n ; ++i ) {
            seg[i] = oo;
        }
        vector<ii> basPos;
        for ( int i = 0 ; i < n ; ++i ) {
            basPos.push_back({baskets[i],i});
        }
        sort(basPos.begin(),basPos.end());
        vector<int> mark(n,0);
        for ( int i = 0 ; i < n ; ++i ) {
            mark[basPos[i].se] = i;
            update(1,0,n - 1,i,basPos[i].se);
        }
        int ans = 0;
        for ( auto i : fruits ) {
            int l = 0;
            int r = n - 1;
            int pos = -1;
            while ( l <= r ) {
                int mid = (l + r) >> 1;
                if ( basPos[mid].fi >= i ) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if ( pos != -1 ) {
                int val = get(1,0,n-1,pos,n - 1);
                if ( val != oo ) {
                    ans++;
                    update(1,0,n-1,mark[val],oo);
                }
            }
        }
        return n - ans;
    }
};
