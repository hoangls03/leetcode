class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0;
        int sum = 0;
        int pos = 0;
        map<int,int> mark;
        for ( auto i : banned ) {
            mark[i] = 1;
        }
        cout<<'\n';
        for ( int i = 1 ; i <= n ; ++i ) {
           if ( mark[i] == 0 ) {
                if ( sum + i <= maxSum ) {
                    ans++;
                    sum += i;
                }
            }
        }
        return ans;
    }
};
