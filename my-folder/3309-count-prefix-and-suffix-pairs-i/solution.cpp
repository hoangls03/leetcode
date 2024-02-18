class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < i ; ++j ) {
                string s = words[i];
                string t = words[j];
                if ( t.size() <= s.size() ) {
                    bool check = true;
                    for ( int k = 0 ; k < t.size() ; ++k ) {
                        if ( s[k] != t[k] ) check = false;
                    }
                    int count = t.size() - 1;
                    for ( int k = s.size() - 1 ; k >= 0 && count >= 0 ; --k) {
                        if ( s[k] != t[count] ) {
                            check = false;
                        }
                        count--;
                    }
                    ans += check;
                }
                
            }
        }
        return ans;
    }
};
