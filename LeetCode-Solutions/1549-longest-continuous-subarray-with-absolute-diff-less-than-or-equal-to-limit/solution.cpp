class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        multiset<int,greater<int>> ms_max;
        int n = nums.size();
        int r = 0;
        int diff = 0;
        int ans = 0;
        ms.insert(nums[0]);
        ms_max.insert(nums[0]);
        for ( int i = 0 ; i < n ; ++i ) {
            diff = *ms_max.begin() - *ms.begin();
            while ( r < n && diff <= limit ) {
                ans = max(ans,r-i+1);
                cout<<r<<" "<<diff<<'\n';
                r++;
                if ( r < n ) {
                    ms.insert(nums[r]);
                    ms_max.insert(nums[r]);
                }
                int max_num = *ms_max.begin();
                int min_num = *ms.begin();
                diff = max_num - min_num;
            }
            auto it = ms.find(nums[i]);
            if (it != ms.end() ) {
                ms.erase(it);
            }
            it = ms_max.find(nums[i]);
            if ( it != ms_max.end() ) ms_max.erase(it);
        } 
        return ans;
    }
};
