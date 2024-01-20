#define ii pair<int,int>
#define fi first
#define se second
const int oo = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        set<int> s;
        set<int,greater<int>> ss;
        int n = arr.size();
        ii a[n+5];
        for ( int i = 0 ; i < arr.size() ; ++i ) {
            a[i].fi = arr[i];
            a[i].se = i;
        }
        sort(a,a+n);
        long long ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            auto l1 = ss.lower_bound(a[i].se);
            auto r1 = s.lower_bound(a[i].se);
            int l,r;
            if ( l1 == ss.end() ) {
                l = 0;
            }
            else l = *l1 + 1;
            if ( r1 == s.end() ) {
                r = n-1;
            }
            else r = *r1 - 1;
            //cout<<l<<" "<<r<<" "<<a[i].se<<'\n';
            ans = (ans + (1LL*(r-a[i].se)*(a[i].se -l) + (r-a[i].se) + (a[i].se -l) + 1)*a[i].fi%oo)%oo;
            s.insert(a[i].se);
            ss.insert(a[i].se);
        }
        return ans;
    }
};
