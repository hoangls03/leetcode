class Solution {
public:
    int findClosest(int x, int y, int z) {
        int first = abs(x - z);
        int second = abs(y-z);
        if ( first == second ) return 0;
        if ( first > second ) return 2;
        return 1;
    }
};
