class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int temp = 0;
        for ( auto i : nums ) {
            temp ^= i;
        }
        int pos;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( ((temp >> i)&1) != 0 ) {
                pos = i;
                break;
            } 
        }
        int x = 0;
        for ( auto i : nums ) {
            if( ((i >> pos)&1) ) {
                x ^= i;
            }
        }
        int y = temp^x;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};
