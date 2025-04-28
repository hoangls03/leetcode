class Solution {
public:
    long long seg[400005];
    void update( int id, int l, int r, int u, int val ) {
        if ( u < l || r < u ) {
            return ;
        }
        if ( l == r ) {
            seg[id] = val;
            return ;
        }
        int mid = ( l + r ) >> 1;
        update(id*2,l,mid,u,val);
        update(id*2+1,mid + 1,r,u,val);
        seg[id] = seg[id*2] + seg[id*2+1];
    }
    long long get(int id, int l, int r, int u, int v ) {
        if ( v < l || r < u ) {
            return 0;
        }
        if ( u <= l && r <= v ) {
            return seg[id];
        }
        int mid = ( l + r ) >> 1;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        vector<int> pos(1e5 + 1,0);
        int n = nums1.size();
        long long ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            pos[nums2[i]] = i + 1;
        }
        vector<int> lessPos(n + 1,0);
        for ( int i = 0 ; i < n ; ++i ) {
            lessPos[i] = get(1,1,n,1,pos[nums1[i]]);
            update(1,1,n,pos[nums1[i]],1);
        }
        for ( int i = 0 ; i <= 4*n ; ++i ) {
            seg[i] = 0;
        }
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            long long tmp = get(1,1,n,pos[nums1[i]],n);
            ans += tmp*lessPos[i];
            update(1,1,n,pos[nums1[i]],1);
        }
        for ( int i = 0 ; i <= 4*n ; ++i ) {
            seg[i] = 0;
        }
        return ans;
    }
};
