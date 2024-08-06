auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    int minimumPushes(string word) {
        int count[26];
        for ( int i = 0 ; i < 26 ; ++i ) 
            count[i] = 0;
        for ( auto i : word ) {
            count[i-'a']++;
        }
        int distinct = 0;
        int ans = 0;
        sort(count,count+26);
        for ( int i = 25 ; i >= 0 ; --i ) {
            if ( count[i] == 0 ) {
                break;
            } else {
                distinct++;
                int order = distinct/8 + 1 - (distinct % 8 == 0 );
                ans += order*count[i];
            }
        }
        return ans;
    }
};
