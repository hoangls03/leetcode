#define ii pair<int,int>
#define iii pair<ii,ii>
#define fi first
#define se second
class Solution {
public:
    
    int root ( int u , vector<int>& parent) {
        if ( parent[u] != u ) parent[u] = root(parent[u], parent);
        return parent[u];
    }
    bool join(int x , int y, vector<int>& parent ) {
        int u = root(x,parent);
        int v = root(y,parent);
        if ( u == v) return false;
        parent[u] = v;
        return true;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int m = edges.size();
        vector<int> parent(n + 5,-1), mark(m + 5,0);
        for ( int i = 0 ; i < n ; ++i ) {
            parent[i] = i;
        }
        priority_queue<iii, vector<iii>> pq;

        int ans = 1e9;
        int id = 0;
        for ( auto e : edges ) {
            if ( e[3] == 1 ) {
                if ( !join(e[0],e[1],parent) ) {
                    return -1;
                }
                ans = min(ans,e[2]);
            } else {
                pq.push({{e[2],id},{e[0],e[1]}});
            }
            id++;
        }

        vector<ii> nums;
        while ( pq.size() ) {
            auto x = pq.top();
            auto e = x.se;
            auto y = x.fi;
            int val = y.fi;
            int id = y.se;
            pq.pop();

            int u = root(e.fi,parent);
            int v = root(e.se,parent);
            if ( u != v ) {
                nums.push_back({val,id});
                join(e.fi,e.se,parent);
            }
        }

        reverse(nums.begin(),nums.end());
        for ( auto i : nums ) {
            if ( k > 0 && mark[i.se] == 0 ) {
                ans = min(ans,i.fi * 2);
                mark[i.se] = 1;
                k--;
            } else {
                ans = min(ans,i.fi);
            }
        }
        int treeRoot = root(0,parent);
        for ( int i = 0 ; i < n ; ++i ) {
            if ( root(i, parent) != treeRoot ) {
                return -1;
            }
        }
        return ans;
    }
};
