class Solution {
public:
    long long seg[1000005];
    void update( int id ,int l , int r , int u , int v) {
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
        seg[id]=seg[id*2] + seg[id*2+1];
    }
    long long get ( int id , int l ,int r , int u , int v) {
        if ( v < l || r < u )
            return 0;
        if  ( u <= l && r <= v)
            return seg[id];
        int mid = ( l + r )>>1;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        update(1,1,n,1,0);
        update(1,1,n,n,0);
        for ( int i = 1 ; i < n - 1  ; ++i ) {
            if ( nums[i] > nums[i-1] && nums[i] > nums[i+1] ) {
                update(1,1,n,i+1,1);
            }
            else update(1,1,n,i+1,0);
        }
        vector<int> ans;
        for ( int i = 0 ; i < queries.size() ; ++i ) {
            int index = queries[i][0];
            int l = queries[i][1] + 1;
            int r = queries[i][2] + 1;
            if ( index == 1 ) {
                ans.push_back(get(1,1,n,l+1,r-1));
            } else {
                l = l -1;
                r = r - 1;
                nums[l] = r;
                if ( l + 2 < n ) {
                    if ( nums[l+1] > nums[l] && nums[l+1] > nums[l+2] ) update(1,1,n,l+1+1,1);
                    else update(1,1,n,l+2,0);
                }
                if ( l - 2 >= 0 ) {
                    if ( nums[l-1] > nums[l] && nums[l-1] > nums[l-2] ) update(1,1,n,l-1+1,1);
                    else update(1,1,n,l-1+1,0);
                }
                if ( l + 1 < n && l - 1 >= 0 ) {
                    if ( nums[l] > nums[l+1] && nums[l] > nums[l-1] ) update(1,1,n,l+1,1);
                    else update(1,1,n,l+1,0);
                }
            }
        }
        return ans;
    }
};
