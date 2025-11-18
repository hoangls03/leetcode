class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        while ( i < n ) {
            if ( i == n - 1 ) {
                return true;
            }
            if ( bits[i] == 1 ) {
                i += 2;
            } else {
                i++;
            }
        }
        return false;
    }
};
