class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int n = arr.length;
        int l = 0;
        int r = n - 1;
        int ans = 0;
        if ( arr[0] > arr[1] ) return 0;
        if ( arr[n-2] < arr[n-1] ) return n - 1;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            if ( mid == n - 1 || arr[mid] > arr[mid+1] ) {
                if ( arr[mid] > arr[mid-1] ) return mid;
                r = mid;
            } else if ( arr[mid] < arr[mid+1] ) {
                l = mid + 1;
            } 
        }
        return ans;
    }
}
