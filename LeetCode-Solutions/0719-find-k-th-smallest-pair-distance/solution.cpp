class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n-1] - nums[0];
        int temp = -1;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            int pos = 1;
            int count = 0;
            bool check = false;
            for ( int i = 0 ; i < n ; ++i ) {
                pos = max(pos,i+1);
                while ( pos < n && nums[pos] - nums[i] <= mid ) {
                    pos++;
                }
                if ( pos >=n || nums[pos] - nums[i] > mid ) {
                    pos--;
                }
                if ( nums[pos] - nums[i] == mid ) check = true;
                count += pos - i;
            }
            if ( count >= k ) {
                temp = mid;
                r = mid - 1;
            } else { 
                l = mid + 1;
            }
        }
        int ans = 1e9;
        int pos = 1;
        for ( int i = 0 ; i < n ; ++i ) {
            int val = nums[i] + temp;
            pos = max(pos,i+1);
            while ( pos < n && nums[pos] < val ) {
                pos++;
            }
            if ( pos < n ) ans = min(ans,nums[pos]-nums[i]); 
        }
        return ans;
    }
};
