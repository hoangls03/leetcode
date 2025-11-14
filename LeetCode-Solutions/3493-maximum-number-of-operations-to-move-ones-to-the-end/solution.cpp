class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int count1 = 0;
        int count0 = 0;
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            count0 += ( s[i] == '0' );
            if ( s[i] == '1' || i == n - 1 ) {
                if ( count0 != 0 ) ans += count1;
                count0 = 0;
                count1++;
            } 
        }
        return ans;
    }
};
