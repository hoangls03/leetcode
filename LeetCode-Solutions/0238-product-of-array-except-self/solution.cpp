class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1,p1 = 1,count = 0;
        vector<int> ans;
        for ( auto i : nums ) {
            if ( i == 0 )  {
                count++;
            } else {
                p = p * i;
            }
            p1 = p1*i;
        }
        for ( auto i : nums ) {
            if ( i != 0 ) ans.push_back(p1/i);
            else {
                if ( count > 1 ) ans.push_back(0);
                else ans.push_back(p);
            }
        }
        return ans;
    }
};
