class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for ( auto i : nums ) {
            mp[i]++;
        }
        sort(nums.begin(),nums.end());
        int ans = 0;
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            if ( i == 0 || nums[i] != nums[i-1] ) {
                if ( mp[nums[i]] == 1 ) return -1;
                if ( mp[nums[i]] % 3 == 0 ) {
                    ans += mp[nums[i]]/3;
                }
                if ( mp[nums[i]] % 3 == 1 ) {
                    ans += mp[nums[i]]/3 - 1 + 2;
                }
                if ( mp[nums[i]] % 3 == 2 ) {
                    ans += mp[nums[i]]/3 + 1;
                }
                //cout<<nums[i]<<" "<<mp[nums[i]]<<" "<<ans<<'\n';
            }
        }
        return ans;
    }
};
