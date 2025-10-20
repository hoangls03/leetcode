class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for ( auto s : operations ) {
            int add = 1;
            bool minus = false;
            for ( auto i : s ) {
                if ( i == '-' ) {
                    minus = true;
                    break;
                }
            }
            if ( minus ) add = -1;
            ans += add;
        }
        return ans;
    }
};
