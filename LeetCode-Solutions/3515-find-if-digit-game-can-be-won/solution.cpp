class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum = 0;
        int sum1 = 0;
        for ( auto i : nums ) {
            if ( i < 10 ) sum += i;
            else sum1 += i;
        }
        if ( sum == sum1 ) return false;
        return true;
    }
};
