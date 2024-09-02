class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int temp = abs(coordinate2[0] - coordinate1[0]);
        int temp2 = abs(coordinate2[1] - coordinate1[1]);
        if ( temp & 1 ) {
            if ( temp2 & 1 ) return true;
        } else {
            if ( temp2 % 2 == 0 ) return true;
        }
        return false;
    }
};
