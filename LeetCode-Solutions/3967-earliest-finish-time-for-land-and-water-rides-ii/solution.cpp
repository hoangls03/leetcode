class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        vector<vector<int>> a,b;
        for ( int i = 0 ; i < n ; ++i ) {
            a.push_back({landStartTime[i], landDuration[i]});
        }
        for ( int i = 0 ; i < m ; ++i ) {
            b.push_back({waterStartTime[i], waterDuration[i]});
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int> minA(n,1e9),minB(m,1e9), minAsuf(n,1e9), minBsuf(m,1e9);
        minA[0] = a[0][1];
        for ( int i = 1 ; i < n ; ++i ) {
            minA[i] = min(minA[i-1],a[i][1]);
        }
        minAsuf[n - 1] = a[n-1][0] + a[n-1][1];
        for ( int i = n - 2 ; i >= 0 ; --i ) {
            minAsuf[i] = min(minAsuf[i+1], a[i][0] + a[i][1]);
        }
        minB[0] = b[0][1];
        for ( int i = 1 ; i < m ; ++i ) {
            minB[i] = min(minB[i-1],b[i][1]);
        }
        minBsuf[m - 1] = b[m-1][0] + b[m-1][1];
        for ( int i = m - 2 ; i >= 0 ; --i ) {
            minBsuf[i] = min(minBsuf[i+1], b[i][0] + b[i][1]);
        }
        int ans = 1e9;
        for ( int i = 0 ; i < n ; ++i ) {
            int minStart = a[i][0] + a[i][1];
            int l = 0, r = m - 1, pos = -1;
            while ( l <= r ) {
                int mid = (l + r)>>1;
                if ( b[mid][0] <= minStart ) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if ( pos != -1 ) {
                ans = min(ans, minStart + minB[pos]);
            }

            if ( pos < m - 1 ) {
                ans = min(ans, minBsuf[pos + 1]);
            }
        }

        for ( int i = 0 ; i < m ; ++i ) {
            int minStart = b[i][0] + b[i][1];
            int l = 0, r = n - 1, pos = -1;
            while ( l <= r ) {
                int mid = (l + r)>>1;
                if ( a[mid][0] <= minStart ) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if ( pos != -1 ) {
                ans = min(ans, minStart + minA[pos]);
            }

            if ( pos < n - 1 ) {
                ans = min(ans, minAsuf[pos + 1]);
            }
        }

        return ans;
    }
};
