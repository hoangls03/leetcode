class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> val(n, n + 1);
        for ( int i = 0 ; i < n ; ++i ) {
            if ( nums[i] == key ) {
                val[i] = 0;
            } else if ( i > 0 ) {
                val[i] = min(val[i],val[i-1] + 1);
            }
        }
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            if ( nums[i] == key ) {
                val[i] = 0;
            } else if ( i < n - 1 ) {
                val[i] = min(val[i],val[i+1] + 1);
            }
        }
        vector<int> ans;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( val[i] <= k ) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
