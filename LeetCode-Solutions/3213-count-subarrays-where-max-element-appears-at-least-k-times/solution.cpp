class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_num = nums[0];
        for ( auto i : nums ) {
            max_num = max(max_num,i);
        }
        long long ans = 0;
        int n = nums.size();
        map<int,int> mp;
        mp.clear();
        int right = 0 ;
        for ( int i = 0  ; i < n ; ++i ) {
            right = max(right,i);
            while ( mp[max_num] < k && right < n ) {
                mp[nums[right]]++;
                right++;
            }
            //cout<<i<<" "<<right<<'\n';
            if ( mp[max_num] >= k ) ans += n - right + 1;
            mp[nums[i]]--;
        }
        return ans;
    }
};
