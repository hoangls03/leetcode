class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long> temp(n+5,-1e18);
        long long ans = 0;
        int dem = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            temp[i] = ( nums[i] ^ k ) - nums[i];
        }
        for ( auto i : nums ) { 
            ans += i;
        }
        sort(temp.rbegin(),temp.rend()); // reverese the sort
        for ( int i = 0 ; i < n - 1 ; i += 2 ) {
            if ( temp[i] + temp[i+1] > 0 ) {
                ans += temp[i] + temp[i+1];
            }
        }
        return ans;
    }
};
