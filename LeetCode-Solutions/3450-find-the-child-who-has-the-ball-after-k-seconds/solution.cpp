class Solution {
public:
    int numberOfChild(int n, int k) {
        int inc = 1;
        int pos = 0;
        while ( k > 0 ) {
            if ( pos == n - 1 ) inc = -1;
            if ( pos == 0 ) inc = 1;
            pos = pos + inc;
            k--;
        }
        return pos;
    }
};
