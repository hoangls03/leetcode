class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        count = (arr[0] & 1);
        int n = arr.size();
        for ( int i = 1 ; i < n ; ++i ) {
            if ( arr[i] & 1 ) {
                count++;
            } else {
                count = 0;
            }
            if ( count == 3 ) return true;
        }
        return false;
    }
};
