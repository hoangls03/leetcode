class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> nums(n + 1,0),sum(n + 1,0);
        sum[0] = 0;
        nums[0] = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            nums[i + 1] = nums[i] + 1LL*skill[i]*mana[0];
            sum[i + 1] = sum[i] + skill[i];
        }
        for ( int i = 1 ; i < m ; ++i ) {
            long long startTime = nums[1];
            for ( int j = 1 ; j <= n ; ++j ) {
                startTime = max(startTime,nums[j] - sum[j-1]*mana[i]);
            }
            nums[0] = startTime;
            for ( int j = 0 ; j < n ; ++j ) {
                nums[j + 1] = nums[j] + mana[i]*skill[j];
            }
        }
        return nums[n];
    }
};
