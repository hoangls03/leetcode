const char vowel[] = {'a','e','i','o','u'};
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int mark[40];
        for ( int i = 0 ; i < 40 ; ++i ) {
            mark[i] = -1;
        }
        int temp = 0;
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            char ch = s[i];
            for ( int j = 0 ; j < 5 ; ++j ) {
                if ( ch == vowel[j] ) {
                    temp ^= (1  << j );
                    
                }
            }
            if ( temp == 0 ) ans = max(ans,i+1);
            if ( mark[temp] == -1 ) {
                mark[temp] = i; 
            } else {
                ans = max(ans,i-mark[temp]);
            
            }
        }
        return ans;
    }
};
