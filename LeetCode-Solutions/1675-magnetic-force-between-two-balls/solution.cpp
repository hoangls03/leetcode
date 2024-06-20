class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int l = 1;
        int r = position[n-1];
        int ans = 0;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            int temp = m;
            bool check = true;
            int pos = 0;
            for ( int i = 0 ; i < n && temp > 0 ; ++i ) {
                if ( position[i] >= pos ) {
                    pos = position[i] + mid;
                    temp--;
                }
            }
            if ( temp == 0 ) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
