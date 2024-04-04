class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        for ( auto i : s ) {
            if ( i == '(' ) count++;
            if ( i == ')' ) count--;
            ans = max(ans,count);
        }
        return ans;
    }
};
