class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> f(26,0);
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            int temp = f[s[i]-'a'];
            for ( int j = 0 ; j < 26 ; ++j ) {
                if ( abs(s[i] - 'a' - j) <= k  ) temp = max(temp,f[j] + 1);
            }
            ans = max(ans,temp);
            f[s[i]-'a'] = temp;
        }

        return ans;
    }
};
