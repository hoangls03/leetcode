class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int right = 0;
        map<int,int> mp;
        vector<bool> here(n,false);
        int ans = 0;
        int dem = 0;
        bool check = true;
        for ( int i = 0 ; i < n ; ++i ) {
            right = max(right,i);
            if ( dem <= k ) check = true;
            while ( right < n && check && dem <= k ) {
                if ( mp[nums[right]] == 0 ) dem++;
                mp[nums[right]]++;
                if ( dem > k ) {
                    check = false;
                    mp[nums[right]]--;
                    dem--;
                } else {
                    right++;
                }
            }
            if ( dem == k  ) {
                ans += right - i;
                here[i] = 1;
            }
            if ( right > i ) {
                mp[nums[i]]--;
                if ( mp[nums[i]] == 0 ) dem--;
            }
        }
        mp.clear();
        right = 0;
        dem = 0;
        check = false;
        for ( int i = 0 ; i < n ; ++i ) {
            right = max(right,i);
            if ( dem <= k - 1 ) check = true;
            while ( right < n && dem <= k-1 && check ) {
                if ( mp[nums[right]] == 0 ) dem++;
                mp[nums[right]]++;
                if ( dem > k-1 ) {
                    check = false;
                    mp[nums[right]]--;
                    dem--;
                } else {
                    right++;
                }
            }
            if ( dem == k-1 && here[i] ) {
                ans -= right - i;
            }
            if ( right > i ) {
                mp[nums[i]]--;
                if ( mp[nums[i]] == 0 ) dem--;
            }
        }
        return ans;
    }
};
