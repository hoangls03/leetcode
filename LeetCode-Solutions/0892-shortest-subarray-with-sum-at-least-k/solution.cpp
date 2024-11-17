const int oo = 1e9;
class Solution {
public:
    int seg[1000005];
    void update( int id, int l, int r, int u, int v ) {
        if ( u < l || r < u ) {
            return ;
        }
        if ( l == r ) {
            seg[id] = v;
            return ;
        }
        int mid = ( l + r ) >> 1;
        update(id*2,l,mid,u,v);
        update(id*2+1,mid + 1,r,u,v);
        seg[id] = max(seg[id*2],seg[id*2+1]);
    }
    int get( int id, int l, int r, int u, int v) {
        if ( v < l || r < u ) {
            return -oo;
        }
        if ( u <= l && r <= v ) {
            return seg[id];
        }
        int mid = ( l + r ) >> 1;
        return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        for ( int i = 0 ; i <= 10*n ; ++i ) {
            seg[i] = -oo;
        }
        vector<long long> comp;
        map<long long,int> mp;
        long long sum = 0;
        comp.push_back(0);
        for ( int i = 0 ; i < n ; ++i ) {
            sum += nums[i];
            comp.push_back(sum);
            comp.push_back(sum-k);
        }
        sort(comp.begin(),comp.end());
        int o = 1;
        mp[comp[0]] = 1;
        for ( int i = 1 ; i < comp.size() ; ++i ) {
            if ( comp[i] != comp[i-1]) {
                mp[comp[i]] = ++o;
            }
        }
        sum = 0;
        int ans = oo;
        update(1,1,o,mp[0],0);
        for ( int i = 0 ; i < n ; ++i ) {
            sum += nums[i];
            int l = get(1,1,o,1,mp[sum-k]);
            if ( l != -oo ) {
                ans = min(ans,i+1-l);
            }
            update(1,1,o,mp[sum],i + 1);
        }
        if ( ans == oo ) ans = -1;
        return ans;
    }
};
