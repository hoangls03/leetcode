class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        for ( auto i : asteroids ) {
            if ( mass >= i ) {
                if ( mass <= 1e6 ) mass += i;
            } else {
                return false;
            }
        }
        return true;
    }
};
