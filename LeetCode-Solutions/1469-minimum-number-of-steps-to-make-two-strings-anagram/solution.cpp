class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26,0),count1(26,0);
        for ( auto i : s ) {
            count[i-'a']++;
        }
        for ( auto i : t ) {
            count1[i-'a']++;
        }
        int ans = 0;
        for ( int i = 0 ; i < 26 ; ++i ) {
            ans += abs(count[i]-count1[i]);
        }
        if ( ans & 1 ) {
            return (ans-1)/2 + 1;
        }
        return ans/2;
    }
};
