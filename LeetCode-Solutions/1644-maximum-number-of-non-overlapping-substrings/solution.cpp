class Solution {
public:
    bool overl(int x, int y, int u, int v) {
        if ( y < u || v < x ) return false;
        if ( x < u && u < y && x < v && v < y ) return false;
        if ( u < x && x < v && u < y && y < v ) return false;
        return true;
    }
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> seg;
        vector<int> st('z' + 5,-1);
        vector<int> en('z' + 5, -1);
        int n = s.size();
        for ( int i = 0 ; i < n ; ++i ) {
            if ( st[s[i]] == -1 ) {
                st[s[i]] = i;
            }
            en[s[i]] = i;
        }
        for ( int i = 0 ; i < n ;  ++i ) {
            for ( int j = 'a' ; j <= 'z' ; ++j ) {
                if ( st[j] < i && i < en[j] ) {
                    en[j] = max(en[j],en[s[i]]);
                    st[j] = min(st[j],st[s[i]]);
                }
            }
        }
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            if ( st[i] != -1 ) {
                for ( int j = 'a' ; j <= 'z' ; ++j ) {
                    if ( st[j] != -1 && j != i ) {
                        if ( overl(st[i],en[i],st[j],en[j])) {
                            // cout<<"before "<<i<<" "<<j<<" "<<st[i]<<" "<<en[i]<<" "<<st[j]<<" "<<en[j]<<'\n';
                            st[i] = min(st[i],st[j]);
                            en[i] = max(en[i],en[j]);
                            st[j] = -1;
                            en[j] = -1;
                            // cout<<i<<" "<<j<<" "<<st[i]<<" "<<en[i]<<" "<<st[j]<<" "<<en[j]<<'\n';
                        }
                    }
                }
            }
        }
        // cout<<"here\n";
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            if ( st[i] != -1 ) {
                // cout<<st[i]<<" "<<en[i]<<'\n';
                seg.push_back({st[i],en[i]});
            }
        }
        sort(seg.begin(),seg.end());
        int m = seg.size();
        vector<int> dp(m + 1,1), sum(m+1,0), prev(m+1,-1);
        int cur = 0, curSum = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            sum[i] = seg[i][1] - seg[i][0] + 1;
            for ( int j = 0 ; j < i ; ++j ) {
                if ( seg[j][1] < seg[i][0] ) {
                    if ( dp[j] + 1 > dp[i] ) {
                        dp[i] = dp[j] + 1;
                        sum[i] = sum[j] + seg[i][1] - seg[i][0] + 1;
                        prev[i] = j;
                    } else if ( dp[j] + 1 == dp[i] ) {
                        if ( sum[j] + seg[i][1] - seg[i][0] + 1 < sum[i] ) {
                            sum[i] = sum[j] + seg[i][1] - seg[i][0] + 1;
                            prev[i] = j;
                        }
                    }
                }
            }
            if ( dp[i] > dp[cur] ) {
                cur = i;
            } else if (dp[i] == dp[cur]) {
                if ( sum[i] < sum[cur] ) {
                    cur = i;
                }
            }
        }
        // cout<<cur<<" "<<dp[cur]<<'\n';
        vector<string> ans;
        while ( cur != -1 ) {
            string subs = s.substr(seg[cur][0], seg[cur][1] - seg[cur][0] + 1);
            ans.push_back(subs);
            cur = prev[cur];
        }
        return ans;
    }
};
