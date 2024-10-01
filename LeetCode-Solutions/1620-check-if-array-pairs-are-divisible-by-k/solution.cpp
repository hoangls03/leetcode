class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> mark(k,0);
        for ( int i = 0 ; i < n ; ++i ) {
            arr[i] %= k;
            if ( arr[i] < 0 ) arr[i] = k + arr[i];
            mark[arr[i]]++;
        }
        for ( int i = 0 ; i < k ; ++i ) {
            if ( i == 0 ) {
                if ( mark[0] & 1 ) return false;
            } else {
                if ( mark[k-i] != mark[i] ) return false;
            }
        }
        return true;
    }
};
