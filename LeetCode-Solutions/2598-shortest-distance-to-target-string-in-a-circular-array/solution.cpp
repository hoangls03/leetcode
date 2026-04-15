class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n + 1;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( words[i] == target ) {
                if ( i <= startIndex ) {
                    ans = min({ans, startIndex - i, n - startIndex + i});
                } else {
                    ans = min({ans, i - startIndex, n - i + startIndex});
                }
            }
        }
        if ( ans == n + 1 ) ans = -1;
        return ans;
    }
};
