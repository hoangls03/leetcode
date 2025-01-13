class Solution {
public:
    int minimumLength(string s) {
        vector<int> count('z' + 1);
        for ( auto i : s ) {
            count[i]++;
        }
        int ans = 0;
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            while ( count[i] >= 3 ) {
                count[i] -= 2;
            }
            ans += count[i];
        }
        return ans;
    }
};
