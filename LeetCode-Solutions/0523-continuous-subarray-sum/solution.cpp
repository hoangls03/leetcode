class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        map<int,int> mark;
        mark.clear();
        mark[0] = 1;
        for ( int i = 0 ; i < n ; ++i ) {
            int temp = sum%k;
            mark[temp]--;
            sum += nums[i];
            if ( i > 0 && mark[sum%k] > 0 ) return true;
            mark[temp]++;
            mark[sum%k]++;
        } 
        return false;
    }
};
