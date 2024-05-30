class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            int temp = arr[i];
            for ( int j = i + 1; j < n ; ++j ) {
                temp ^= arr[j];
                if ( temp == 0 ) {
                    ans+=j-i;
                }
                //cout<<temp<<" "<<i<<" "<<j<<'\n';
            }
        }
        return ans;
    }
};
