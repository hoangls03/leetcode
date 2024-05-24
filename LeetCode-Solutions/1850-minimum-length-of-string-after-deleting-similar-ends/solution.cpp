class Solution {
public:
    int minimumLength(string s) {
        int n = s.size() - 1;
        int l = 0;
        int r = n;
        bool check = false;
        while ( l < r && !check ) {
            char c = s[l];
            check = true;
            while ( s[r] == c && r > 0 ) {
                r--;
                check = false;
            }
            while ( !check && s[l] == c && l < n ) {
                l++;
            }
        }
        int ans = max(0,r-l+1);
        return ans;
    }
};
