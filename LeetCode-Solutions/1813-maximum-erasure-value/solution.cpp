class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        int sum = nums[0];
        int ans = 0;
        vector<int> mark(1e5 + 1,0);
        mark[nums[0]]++;
        for ( int i = 0 ; i < n ; ++i ) {
            while ( pos + 1 < n && mark[nums[pos+1]] == 0 ) {
                pos++;
                mark[nums[pos]]++;
                sum += nums[pos];
            } 
            ans = max(ans,sum);
            sum -= nums[i];
            mark[nums[i]]--;
        }  
        return ans;
    }
};
