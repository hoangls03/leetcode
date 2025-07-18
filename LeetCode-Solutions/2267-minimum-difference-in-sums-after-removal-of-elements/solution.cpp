class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m/3;
        vector<long long> sum(m + 1,0);
        priority_queue<int,vector<int>,greater<int>> pq;
        for ( int i = m - 1 ; i >= 0 ; --i ) {
            if ( pq.size() < n ) {
                pq.push(nums[i]);
                sum[i] = sum[i+1] + nums[i];
            } else {
                sum[i] = sum[i+1];
                if( pq.top() < nums[i] ) {
                    sum[i] += nums[i] - pq.top();
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        priority_queue<int> pq1;
        long long res = 0;
        long long ans = 1e18;
        for ( int i = 0 ; i < m - n; ++i ) {
            if ( pq1.size() < n ) {
                pq1.push(nums[i]);
                res += nums[i];
            } else {
                if ( pq1.top() > nums[i] ) {
                    res += nums[i] - pq1.top();
                    pq1.pop();
                    pq1.push(nums[i]);
                }
            }
            if ( pq1.size() == n ) {
                ans = min(ans,res - sum[i+1]);
            }
        }
        return ans;
    }
};
