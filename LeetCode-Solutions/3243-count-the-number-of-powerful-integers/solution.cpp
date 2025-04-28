class Solution {
public:
    long long cal(string t, string s, int limit) {
        if ( t.size() < s.size() ) return 0;
        if ( t.size() == s.size() ) {
            return (t >= s);
        }
        int n = t.size();
        int m = s.size();
        string suf = t.substr(n - m,m);
        long long ans = 0;
        for ( int i = 0 ; i < n - m ; ++i ) {
            if ( (t[i] - '0' > limit) ) {
                ans += pow(limit+1,n-m-i);
                return ans; //no more to take
            } else {
                ans += 1LL*(t[i] - '0')*pow(limit+1,n - m - i - 1); //we don't need to care about x[i] since we will visit the other options of x[i+1] in the future
            }
        }
        ans += ( suf >= s ); // we can add one more if our suffix is greater than s
        return ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string finishStr = to_string(finish);
        return cal(finishStr,s,limit) - cal(startStr,s,limit);
    }
};
