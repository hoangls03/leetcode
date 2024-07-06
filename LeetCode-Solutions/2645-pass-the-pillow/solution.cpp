class Solution {
public:
    int passThePillow(int n, int time) {
        int round = time/(n-1);
        int pos = time%(n-1);
        int ans = pos + 1;
        if ( round & 1 ) ans = n - pos;
        return ans;
    }
};
