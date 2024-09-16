class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> vt;
        for ( auto time : timePoints ) {
            int temp = 0;
            int convert = 0;
            for ( auto i : time ) {
                if ( i == ':' ) {
                    convert += temp*60;
                    temp = 0;
                } else {
                    temp = temp * 10 + i - '0';
                }
            }
            convert += temp;
            vt.push_back(convert);
        }
        sort(vt.begin(),vt.end());
        int ans = 1e9;
        int n = vt.size();
        for ( int i = 0 ; i < n ; ++i ) {
            int temp = ( i == n - 1 ) ? 24*60 + vt[0] - vt[i] : min(vt[i+1] - vt[i],24*60-vt[i+1]+vt[i]);
            ans = min(ans,temp);
        }
        return ans;

    }
};
