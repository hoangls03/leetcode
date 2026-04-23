class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int,long long> count, sum;
        int n = nums.size();
        for ( int i = 0 ; i < n ; ++i ) {
            count[nums[i]]++;
            sum[nums[i]] += i;
        }
        map<int,long long> curSum,curCount;
        vector<long long> ans;
        long long res = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            res = sum[nums[i]] - curSum[nums[i]] - i*(count[nums[i]] - curCount[nums[i]]);
            res += i*curCount[nums[i]] - curSum[nums[i]];
            ans.push_back(res);
            curSum[nums[i]] += i;
            curCount[nums[i]]++;
        }
        return ans;
    }
};
