class Solution {
public:
    long long seg[800005];
    void update( int id, int l, int r, int pos, int val ) {
        if ( pos < l || pos > r) {
            return ;
        }

        if ( l == r ) {
            seg[id] += val;
            return ;
        }

        int mid = (l + r)>>1;
        
        update(id * 2,l,mid,pos,val);
        update(id * 2 + 1,mid + 1,r,pos,val);

        seg[id] = seg[id*2] + seg[id*2 + 1];
    }

    long long get(int id, int l, int r, int u, int v) {
        if ( v < l || r < u ) {
            return 0;
        }

        if ( u <= l && r <= v ) {
            return seg[id];
        }

        int mid = (l + r)>>1;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid + 1,r,u,v);
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n,0);
        for ( int i = 0 ; i <= 200000 ; ++i ) {
            seg[i] = 0;
        }
        if ( nums[0] == target ) {
            prefix[0] = 1;
        } else {
            prefix[0] = -1;
        }
        for ( int i = 1 ; i < n ; ++i ) {
            if ( nums[i] == target ) {
                prefix[i] = prefix[i-1] + 1;
            } else {
                prefix[i] = prefix[i-1] - 1;
            }
        }
        long long ans = 0;
        update(1,0,200000,100000,1);
        for ( int i = 0 ; i < n ; ++i ) {
            ans += get(1,0,200000,0,prefix[i] + 100000 - 1);
            update(1,0,200000,prefix[i] + 100000,1);
        }
        return ans;
    }
};
