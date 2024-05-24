const long long oo = 1e18;
class Solution {
long long seg[1000005];
void update( int id ,int l , int r , int u , int v )
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
typedef struct {
    int fi;
    int se;
    int val;
} st;
static bool cmp( st a, st b) {
    if ( a.fi == b.fi ) {
        if ( a.se == b.se ) return a.val < b.val;
        return a.se < b.se;
    }
    return a.fi < b.fi;
}
public:
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        map<int,int> f,mp;
        vector<int> RR(2*n);
        for ( int i = 0 ; i < 2*n ; ++i ) {
            if ( i < n ) RR[i] = startTime[i];
            else RR[i] = endTime[i-n];
        }
        sort(RR.begin(),RR.end());
        int count = 1;
        for ( int i = 0 ; i < RR.size() ; ++i ) {
            if ( i == 0 ) mp[RR[i]] = count;
            else {
                if ( RR[i] != RR[i-1] ) {
                    mp[RR[i]] = ++count;
                }
            }
        }
        vector<st> vt(n);
        for ( int i = 0 ; i < n ; ++i ) {
            vt[i].fi = mp[startTime[i]];
            vt[i].se = mp[endTime[i]];
            vt[i].val = profit[i];
        }
        sort(vt.begin(),vt.end(),cmp);
        for ( auto i : vt ) {
            cout<<i.fi<<" "<<i.se<<" "<<i.val<<'\n';
        }
        int temp = -1;
        for ( int i = 0 ; i < vt.size() ; ++i ) {
            if ( i == 0 ) {
                f[vt[i].se] = vt[i].val; 
                update(1,1,2*n,vt[i].se,f[vt[i].se]);
            }
            else {
                f[vt[i].fi] = get(1,1,2*n,1,vt[i].fi);
                update(1,1,2*n,vt[i].se,f[vt[i].fi]);
                
                f[vt[i].se] = max(f[vt[i].se],f[vt[i].fi] + vt[i].val);
                update(1,1,2*n,vt[i].se,f[vt[i].se]);
            }
            cout<<"debug"<<f[3]<<'\n';
        }
        int ans = -1;
        for ( int i = 1 ; i <= 2*n ; ++i ) {
            cout<<f[i]<<'\n';
            ans = max(ans,f[i]);
        }
        return ans;
    }
};
