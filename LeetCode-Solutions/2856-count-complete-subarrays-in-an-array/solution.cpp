class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(2001,0);
        int distinct = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( count[nums[i]] == 0 ) distinct++;
            count[nums[i]]++;
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            fill(count.begin(),count.end(),0);
            int tmp = 0;
            for ( int j = i ; j < n ; ++j ) {
                tmp += count[nums[j]] == 0;
                count[nums[j]]++;
                ans += tmp == distinct;
            }
        }
        return ans;
    }
};
