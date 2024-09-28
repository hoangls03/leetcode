class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 1e9;
        for ( auto num : nums ) {
            int temp = 0;
            while ( num > 0 ) {
                temp += num%10;
                num /= 10;
            }
            ans = min(ans,temp);
        }
        return ans;
    }
};
