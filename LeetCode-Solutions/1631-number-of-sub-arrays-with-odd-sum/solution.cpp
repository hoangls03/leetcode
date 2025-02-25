const int oo = 1e9 + 7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        for ( auto &i : arr ) {
            i = (i & 1);
        }
        long long ans = 0;
        int n = arr.size();
        long long odd = 0, even = 1;
        int sum = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            sum += arr[i];
            if ( sum & 1 ) {
                ans = (ans + even)%oo;
                odd++;
            } else {
                ans = (ans + odd)%oo;
                even++;
            }
        }
        return ans;
    }
};
