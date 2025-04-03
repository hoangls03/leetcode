class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxNum = -1e9, maxPre = -1e9, ans = 0;
        for ( auto i : nums ) {
            ans = max(ans,i*maxNum);
            maxNum = max(maxNum,maxPre - i);
            maxPre = max(maxPre,1LL*i);
        }
        return ans;
    }
};
