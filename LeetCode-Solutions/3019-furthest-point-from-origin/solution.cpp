class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0;
        int count_ = 0;
        int ans = 0;
        for ( auto i : moves ) {
            countL += (i == 'L');
            countL -= (i == 'R');
            count_ += (i == '_');
        }
        ans = abs(countL) + count_;
        return ans;
    }
};
