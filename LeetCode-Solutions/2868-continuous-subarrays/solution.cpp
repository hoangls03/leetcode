class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        multiset<int> ms;
        int pos = 0;
        long long ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            ms.insert(nums[i]);
            while ( ms.size() > 1 && *ms.rbegin() - *ms.begin() > 2 ) {
                ms.erase(ms.find(nums[pos]));
                pos++;
            }
            ans += i - pos + 1;
        }
        return ans;
    }
};
