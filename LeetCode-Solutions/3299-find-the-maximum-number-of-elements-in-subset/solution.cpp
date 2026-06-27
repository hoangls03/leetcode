class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int,int> mark;
        for ( auto i : nums ) {
            mark[i]++;
        }
        int ans = 0;
        for ( auto i : nums ) {
            if ( i != 1 ) {
                long long cur = i;
                for ( int j = 1 ; j <= 5 ; ++j ) {
                    if ( mark[cur] >= 2 ) {
                        cur = cur*cur;
                        ans = max(ans,(j-1)*2 + 1);
                    } else if ( mark[cur] == 1 ) {
                        ans = max(ans,(j-1)*2 + 1);
                        break;
                    }
                    if ( cur > 1e9 ) break;
                }
            }
        }
        if (mark[1] % 2 == 0 ) {
            ans = max(ans,mark[1] - 1);
        } else {
            ans = max(ans,mark[1]);
        }
        return ans;
    }
};
