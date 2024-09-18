class Solution {
public:
    static bool cmp( int a, int b) {
        string s = to_string(a);
        string s1 = to_string(b);
        return ( s + s1 ) > ( s1 + s);
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),cmp);
        string ans = "";
        for ( auto i : nums ) {
            ans += to_string(i);
        }
        if ( ans[0] == '0' ) return "0";
        return ans;
    }
};
