class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = i ; j < n ; ++j ) {
                swap(s2[i],s2[j]);
                if ( s2 == s1 ) return true;
                swap(s2[i],s2[j]);
            }
        }
        return false;
    }
};
