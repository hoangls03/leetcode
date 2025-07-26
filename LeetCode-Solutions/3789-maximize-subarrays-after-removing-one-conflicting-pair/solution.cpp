class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> r(n + 1,n + 1),r1(n + 1,n + 1);
        for ( auto& i : conflictingPairs ) {
            if ( i[0] > i[1] ) swap(i[0],i[1]);
            if ( r[i[0]] > i[1] ) {
                r1[i[0]] = r[i[0]];
                r[i[0]] = i[1];
            } else if ( r1[i[0]] > i[1] ) {
                r1[i[0]] = i[1];
            }
        }

        long long ans = 0;
        int tmp = n + 1,tmp1 = n + 1;
        vector<long long> res(n + 2,0);
        for ( int i = n ; i >= 1 ; --i ) {
            if ( tmp > r[i] ) {
                tmp1 = min(tmp,r1[i]);
                tmp = r[i];
            } else {
                tmp1 = min(tmp1,r[i]);
            }
            ans += tmp - i;
            res[tmp] += tmp1 - tmp;
        }
        ans += *max_element(res.begin(),res.end());
        return ans;
    }
};
