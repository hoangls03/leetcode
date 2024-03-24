class Solution {
const long long oo = 1e18;    
public:
    long long seg[1000005];
    void update( int id ,int l , int r , int u , long long v )
    {
        if ( u < l || r < u )
            return;
        if ( l == r )
        {
            seg[id] = v;
            return;
        }
        int mid  = ( l + r )>>1;
        update(id*2,l,mid,u,v);
        update(id*2+1,mid+1,r,u,v);
        seg[id]=max(seg[id*2],seg[id*2+1]);
    }
    long long get ( int id , int l ,int r , int u , int v)
    {
        if ( v < l || r < u )
            return -oo;
        if  ( u <= l && r <= v)
            return seg[id];
        int mid = ( l + r )>>1;
        return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> ans;
        int n = nums.size();
        map<long long,long long> mp;
        mp.clear();
        for ( int i = 0 ; i < n ; ++i ) {
            mp[nums[i]] += freq[i];
            update(1,1,1e5,nums[i],mp[nums[i]]);
            long long temp = get(1,1,1e5,1,1e5);
            ans.push_back(temp);
        }
        return ans;
    }
};
