#define ii pair<int,int>
#define fi first
#define se second
class Solution {
    
public:
    static bool cmp ( ii a , ii b ) {
        if ( a.fi == b.fi) return a.se > b.se;
        return a.fi < b.fi;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        ii a[n];
        for ( int i = 0 ; i < n ; ++i ) {
            a[i].fi = points[i][0];
            a[i].se = points[i][1];
        }
        int ans = 0;
        sort(a,a+n,cmp);
        /*for ( auto i : a ) {
            cout<<i.fi<<" "<<i.se<<'\n';
        }*/
        vector<vector<ii>> q(n);
        for ( int i = 0 ; i < n ; ++i ) {
            set<int> st;
            for ( int j = i + 1 ; j < n ; ++j ) {
                
                if ( a[i].se >= a[j].se ) {
                    bool check = true;
                    auto it = st.lower_bound(a[j].se);
                    
                    if ( it != st.end() ) check = false;
                    //if ( i == 0 && j == 2 ) cout<<st.size()<<" "<<*st.begin()<<" "<<a[j].se<<'\n';
                    if ( check ) { 
                        st.insert(a[j].se);
                    }
                    ans += check;
                    
                   
                }
            }
            st.clear();
        }
        return ans;
    }
};
