class Solution {
public:
    string getSmallestString(string s) {
        for ( int i = 0 ; i < s.size() - 1 ; ++i ) {
            int current = s[i] - '0';
            int next = s[i+1] - '0';
            if ( ( current + next )% 2 == 0 && current > next ) {
                swap(s[i],s[i+1]);
                break;
            }
        }
        return s;
    }
};
