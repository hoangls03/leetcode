class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        mp.clear();
        int right = 0;
        bool check = true;
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            right = max(right,i);
            while ( check && right < n ) {
                mp[nums[right]]++;
                if ( mp[nums[right]] > k ) {
                    check = false;
                    break;
                }
                right++;
            }
            //cout<<right<<" "<<i<<'\n';
            if ( right - 1 >= i ) ans = max(ans,right - i);
            mp[nums[i]]--;
            if ( right < n && mp[nums[right]] <= k ) {
                check = true;
                right++;
            }
        }
        return ans;    
    }
};
