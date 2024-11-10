class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mark(34,0),vis(n,0);
        int pos = 0,cur = nums[0];
        int ans = 1e6;
        int num = nums[0];
        while ( num > 0 ) {
            int temp = log2(num);
            mark[temp]++;
            num -= ( 1 << temp );
        }
        for ( int i = 0  ; i < n ; ++i ) {
            pos = max(pos,i);
            while ( pos < n - 1 && cur < k ) {
                pos++;
                if ( vis[pos] == 0 ) {
                    num = nums[pos];
                    while ( num > 0 ) {
                        int temp = log2(num);
                        mark[temp]++;
                        if ( mark[temp] == 1 ) {
                            cur += ( 1 << temp );
                        }
                        num -= ( 1 << temp );
                    }
                }
                vis[pos] = 1;
                if ( cur >= k ) {
                    ans = min(ans,pos-i+1);
                }
            }
            if ( cur >= k ) {
                ans = min(ans,pos-i+1);
            }
            num = nums[i];
            while ( num > 0 ) {
                int temp = log2(num);
                mark[temp]--;
                if ( mark[temp] == 0 ) {
                    cur -= ( 1 << temp );
                }
                num -= ( 1 << temp );
            }
        } 
        if ( ans == 1e6 ) ans = -1;
        return ans;
    }
};
