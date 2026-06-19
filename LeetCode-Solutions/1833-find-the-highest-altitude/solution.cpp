class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, atd = 0;
        for ( auto i : gain ) {
            atd += i;
            ans = max(ans,atd);
        }
        return ans;
    }
};
