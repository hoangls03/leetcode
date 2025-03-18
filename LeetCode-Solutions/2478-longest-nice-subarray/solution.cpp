class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int ans = 0;
        vector<int> mark(33,0);
        for ( int i = 0 ; i < n ; ++i ) {
            bool check = true;
            while ( r < i ) {
                int tmp = nums[r];
                while ( tmp > 0 ) {
                    int val = log2(tmp);
                    mark[val]++;
                    tmp -= (1 << val);
                }
                r++;
            }
            //cout<<i<<" "<<r<<'\n';
            while ( (r < n && check )  ) {
                int tmp = nums[r];
                check = true;
                while ( tmp > 0 ) {
                    int val = log2(tmp);
                    if ( mark[val] != 0 ) {
                        check = false;
                        break;
                    }
                    tmp -= (1 << val);
                }
                //cout<<i<<" "<<r<<" "<<check<<'\n';
                if ( check ) {
                    tmp = nums[r];
                    while ( tmp > 0 ) {
                        int val = log2(tmp);
                        mark[val]++;
                        tmp -= (1 << val);
                    }
                    ans = max(ans,r - i + 1);
                    r++;
                }
            }
            int tmp = nums[i];
            while ( tmp > 0 ) {
                int val = log2(tmp);
                mark[val]--;
                tmp -= (1 << val);
            }
        }
        return ans;
    }
};
