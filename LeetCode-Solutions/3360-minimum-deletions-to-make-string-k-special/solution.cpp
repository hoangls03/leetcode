class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> count('z' + 1,0);
        for ( auto i : word ) {
            count[i]++;
        }
        sort(count.begin(),count.end());
        vector<int> nums;
        for ( auto i : count ) {
            if ( i != 0 ) {
                nums.push_back(i);
            }
        }
        int n = nums.size();
        vector<int> suffix(n + 1,0);
        for ( int i = n -  1 ; i >= 0 ; --i ) {
            suffix[i] = suffix[i+1] + nums[i];
        }
        int ans = 1e9;
        int sum = 0;
        int r = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            while ( r + 1 < n && nums[r+1] - nums[i] <= k ) {
                r++;
            }
            int dis = n - 1 - r;
            int tmp = suffix[r+1] - dis*max(nums[r],nums[i] + k);
            ans = min(ans,tmp + sum);
            sum += nums[i]; 
        }
        return ans;
    }
};
