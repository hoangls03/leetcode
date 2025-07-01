class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> mark('z' + 1);
        int n = word.size();
        int count = 1;
        int ans = 1;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( word[i] == word[i-1] ) {
                count++;
            } else {
                ans += count - 1;
                count = 1;
            }
        }
        ans += count - 1;
        return ans;
    }
};
