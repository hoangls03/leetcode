class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxNum = 1;
        for ( auto &i : nums ) {
            maxNum = max(maxNum,i);
            i = __gcd(maxNum,i);
        } 

        sort(nums.begin(),nums.end());

        int n = nums.size();
        long long sum = 0;
        for ( int i = 0 ; i < n/2 ; ++i ) {
            sum += __gcd(nums[i],nums[n-i-1]);
        }
        return sum;
    }
};
