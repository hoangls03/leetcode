class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        
        int cnt1 = 0;
        for ( auto i : s ) {
            cnt1 += (i == '1');
        }

        vector<int> zeros;
        int pos = 0;
        while ( pos < n ) {
            int start = pos;

            while ( pos < n && s[pos] == s[start] ) {
                pos++;
            } 

            if ( s[start] == '0' ) {
                zeros.push_back(pos - start);
            }
        }

        int m = zeros.size();

        if ( m <= 1 ) {
            return cnt1;
        }

        int ans = 0;
        for ( int i = 0 ; i < m - 1 ; ++i ) {
            ans = max(ans,zeros[i] + zeros[i+1]);
        }

        ans += cnt1;

        return ans;
    }
};
