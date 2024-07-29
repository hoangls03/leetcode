class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> r(n,0);
        r[n-1] = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            for ( int j = i - 1 ; j >= 0 ; --j ) {
                if ( rating[j] < rating[i] ) {
                    r[j]++;
                }
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = i + 1 ; j < n ; ++j ) {
                if ( rating[i] < rating[j] ) {
                    ans += r[j];
                }
            }
        }
        reverse(rating.begin(),rating.end());
        fill(r.begin(),r.end(),0);
        r[n-1] = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            for ( int j = i - 1 ; j >= 0 ; --j ) {
                if ( rating[j] < rating[i] ) {
                    r[j]++;
                }
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = i + 1 ; j < n ; ++j ) {
                if ( rating[i] < rating[j] ) {
                    ans += r[j];
                }
            }
        }
        return ans;
    }
};
