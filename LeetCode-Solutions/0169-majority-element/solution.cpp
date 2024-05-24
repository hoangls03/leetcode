class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1,ans;
        sort(nums.begin(),nums.end());
        for ( int i = 1 ; i < n ; ++i ) {
            if ( nums[i] == nums[i-1] ) {
                count++;
                if ( count > n/2 ) ans = nums[i];
            }
            else {
                count = 1;
            }
            cout<<count<<'\n';
        }
        if ( n == 1 ) ans = nums[0];
        return ans;
    }
};
