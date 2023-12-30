class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> countw(26,0);
        for ( auto s : words ) {
            for ( char i : s ) {
                countw[i-'a']++;
            }
        }
        int temp = -1;
        if ( words.size() == 1 ) return true;
        for ( int i = 0 ; i < 26 ; ++i ) {
            if ( countw[i] != 0 ) {
                if ( countw[i] % words.size() != 0 ) {
                    return false;
                }
            }
        }
        return true;
    }
};
