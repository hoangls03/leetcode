class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size() - 1;
        int carry = 1;
        while ( n >= 0 ) {
            int digit = digits[n] + carry;
            if ( digit >= 10 ) {
                ans.push_back(0);
                carry = 1;
            } else {
                ans.push_back(digit);
                carry = 0;
            }
            n--;
        }
        if ( carry == 1 ) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
