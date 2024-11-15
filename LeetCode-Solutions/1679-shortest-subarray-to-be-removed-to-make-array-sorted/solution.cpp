class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n,0);
        l[0] = 0;
        int ans = n - 1;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( arr[i] >= arr[i-1] && l[i-1] == i - 1 ) {
                l[i] = i;
                ans = min(ans,n-i-1);
            } else l[i] = l[i-1];
        }
        vector<int> r(n,n-1);
        r[n-1] = n-1;
        for ( int i = n - 2 ; i >= 0 ; --i ) {
            if ( arr[i] <= arr[i+1] && r[i+1] == i + 1 ) {
                r[i] = i;
                ans = min(ans,i);
            } else {
                r[i] = r[i+1];
            }
        }
        int left = 0;
        int right = n - 1;
        while ( left <= right ) {
            int mid = ( left + right ) >> 1;
            bool check = false;
            for ( int i = 0 ; i < n - mid -1; ++i ) {
                if ( arr[i] <= arr[i+mid+1] && l[i] == i && r[i+mid+1] == i + mid + 1 ) {
                    ans = min(ans,mid);
                    check = true;
                    break;
                }
            }
            if ( check ) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
