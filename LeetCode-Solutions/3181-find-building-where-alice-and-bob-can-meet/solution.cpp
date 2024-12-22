const int oo = 1e9 + 7;
class Solution {
public:
    void buildTree (vector<int>& sTree, int idx, int start, int end, const vector<int>& a) {
        if (start == end) {
            sTree[idx] = a[start];
            return;
        }
        int mid = (start+end)/2;
        buildTree (sTree, 2*idx+1, start, mid, a);
        buildTree (sTree, 2*idx+2, mid+1, end, a);
        sTree[idx] = max(sTree[2*idx+1], sTree[2*idx+2]);
    }
    int get ( vector<int>& seg, int id , int l ,int r , int u , int v) {
        if ( v < l || r < u )
            return -oo;
        if  ( u <= l && r <= v)
            return seg[id];
        int mid = ( l + r )>>1;
        return max(get(seg,id*2 + 1,l,mid,u,v),get(seg,id*2+2,mid+1,r,u,v));
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int m = queries.size();
        vector<int> res;
        vector<int> seg(4*n,-oo);
        for ( int i = 0 ; i < 4*n ; ++i ) {
            seg[i] = 0;
        }
        buildTree (seg, 0, 0, n-1, heights);
        for ( auto q : queries ) {
            if ( q[0] > q[1] ) swap(q[0],q[1]);
            int l = max(q[0],q[1]);
            int r = n - 1;
            int val = max(heights[q[0]],heights[q[1]]);
            int ans = -1;
            if ( heights[q[1]] > heights[q[0]] || q[1] == q[0]) {
                res.push_back(q[1]);
                continue;
            }
            val++;
            while ( l <= r ) {
                int mid = ( l + r ) >> 1;
                if ( get(seg,0,0,n-1,l,mid) >= val ) {
                    if ( ans != -1 ) ans = min(ans,mid);
                    else ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
