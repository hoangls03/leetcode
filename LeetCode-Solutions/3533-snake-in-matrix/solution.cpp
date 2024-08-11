class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans = 0;
        for ( auto s : commands ) {
            if ( s == "UP" ) ans -= n;
            if ( s == "DOWN" ) ans += n;
            if ( s == "RIGHT" ) ans++;
            if ( s == "LEFT" ) ans--;
        }
        return ans;
    }
};
