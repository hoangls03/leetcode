class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int tmp = 0;
        for ( auto i : dimensions ) {
            if ( i[0]*i[0] + i[1]*i[1] == tmp ) {
                ans = max(ans,i[0]*i[1]);
            }
            if ( i[0]*i[0] + i[1]*i[1] > tmp ) {
                ans = i[0]*i[1];
                tmp = i[0]*i[0] + i[1]*i[1];
            }
        }
        return ans;
    }
};
