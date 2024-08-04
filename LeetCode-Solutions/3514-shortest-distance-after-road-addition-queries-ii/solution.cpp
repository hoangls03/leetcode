class Solution {
public:
    int laz[1000005],seg[1000005];
    void update(int id , int l , int r , int u , int v , int val)
    {
        seg[id] += laz[id]*(r - l + 1) ;
        laz[2*id] += laz[id];
        laz[2*id+1] += laz[id];
        laz[id] = 0 ;
        if(u > r || v < l) {
            return ;
        }
        if(l >= u && r <= v) {
            seg[id] = val*(r - l + 1) ;
            laz[2*id] += val ;
            laz[2*id+1] += val ;
            return ;
        }
        int mid = (l+r)>>1;
        update(2*id , l , mid , u , v , val) ;
        update(2*id + 1 , mid + 1 , r , u , v , val) ;
        seg[id] = seg[2*id] + seg[2*id+1];

    }
    long long get(int id ,int l , int r , int u , int v)
    {
        seg[id] += laz[id]*(r - l + 1) ;
        laz[2*id] += laz[id] ;
        laz[2*id+1] += laz[id] ;
        laz[id] = 0 ;
        if( u > r || v < l) {
            return 0;
        }
        if(l >= u && r <= v)
        {
            return seg[id] ;
        }
        int mid = ( l + r )>>1;
        return (get(2*id , l , mid , u , v) + get(2*id + 1 , mid + 1 , r , u , v)) ;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        int temp = n-1;
        for ( auto e : queries ) {
            int u = e[0];
            int v = e[1];
            if ( get(1,1,n,u+2,v) < v - u - 1 ) {
                temp += get(1,1,n,u+2,v);
                update(1,1,n,u+2,v,1);
                temp -= ( v - u - 1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
