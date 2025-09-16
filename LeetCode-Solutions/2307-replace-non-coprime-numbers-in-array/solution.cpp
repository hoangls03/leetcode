class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        int tmp = nums[0];
        int n = nums.size();
        for ( int i = 1 ; i < n ; ++i ) {
            if ( __gcd(tmp,nums[i]) == 1 ) {
                ans.push_back(tmp);
                tmp = nums[i];
            } else {
                tmp = nums[i]/__gcd(tmp,nums[i])*tmp;
                while( ans.size() && __gcd(ans[ans.size() - 1],tmp) > 1 ) {
                    tmp = tmp/__gcd(ans[ans.size() - 1],tmp)*ans[ans.size() - 1];
                    ans.pop_back();
                }
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};
