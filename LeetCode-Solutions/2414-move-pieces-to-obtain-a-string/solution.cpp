class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int Rstack = 0;
        int Lneed = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            char cur = start[i];
            char goal = target[i];
            if ( cur == 'R' ) {
                if ( Lneed > 0 ) return false;
                Rstack++;
            }
            if ( goal == 'L' ) {
                if ( Rstack > 0 ) return false;
                Lneed++;
            }
            if ( cur == 'L' ) {
                if ( Lneed == 0 ) return false;
                Lneed--;
            }
            if ( goal == 'R' ) {
                if ( Rstack == 0 ) return false;
                Rstack--;
            }
        }
        return (Lneed == 0 && Rstack == 0);
    }
};
