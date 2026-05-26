class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> mark('z' + 1);
        for ( auto i : word ) {
            mark[i] = 1;
        }
        int ans = 0;
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            int diff = 'A' - 'a';
            if ( mark[i] == 1 && mark[i + diff] == 1 ) {
                ans++;
            }
        }
        return ans;
    }
};
