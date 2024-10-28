class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        int ans = 0;
        for ( auto num : nums ) {
            int temp = sqrt(num);
            if ( temp*temp == num ) {
                mp[num] = mp[temp] + 1;
                ans = max(ans,mp[num]);
            }
            mp[num] = max(mp[num],1);
        }
        return ans <= 1 ? -1 : ans;
    }
};
