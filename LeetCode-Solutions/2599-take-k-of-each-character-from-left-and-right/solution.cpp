class Solution {
public:
    bool check( vector<int>& mark, vector<int>& r, int& k ) {
        for ( int i = 0 ; i < 3 ; ++i ) {
            if ( mark[i] + r[i] < k ) return false; 
        }
        return true;
    }
    int takeCharacters(string s, int k) {
        int n = s.size();
        int ans = 1e9;
        vector<int> mark('c',0),r('c',0);
        for ( int j = n - 1 ; j >= 0 ; --j ) {
            r[s[j]-'a']++;
            if ( check(mark,r,k) ) ans = min(ans,n-j);
        }
        if ( k == 0 ) return 0;
        r[s[0]-'a']--;
        int pos = 1;
        for ( int i = 0 ; i < n ; ++i ) {
            mark[s[i]-'a']++;
            while ( pos <= i ) {
                r[s[pos]-'a']--;
                pos++;
            }
            if ( check(mark,r,k) ) {
                ans = min(ans,i+1+n-pos);
            }
            while ( pos < n && check(mark,r,k) ) {
                if ( check(mark,r,k) ) {
                    ans = min(ans,i+1+n-pos);
                }
                r[s[pos]-'a']--;
                pos++;
                if ( check(mark,r,k) ) {
                    ans = min(ans,i+1+n-pos);
                }
            }
        }
        if ( ans == 1e9 ) ans = -1;
        return ans;
    }
};
