class Solution {
public:
    int cal(vector<vector<int>>& sum, int i, int j, int k , int l) {
        return sum[k][l] - sum[i-1][l] - sum[k][j-1] + sum[i-1][j-1];
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> sum(m+1,vector<int> (n+1,0));
        for ( int i = 0 ; i <= m ; ++i ) {
            for ( int j = 0 ; j <= n ; ++j ) {
                sum[i][j] = 0;
            }
        }
        for ( int i = 1 ; i <= m ; ++i ) {
            int temp = 0;
            for ( int j = 1 ; j <= n ; ++j ) {
                temp += img[i-1][j-1];
                sum[i][j] = sum[i-1][j] + temp;
            }
        }
        for ( int i = 1 ; i <= m ; ++i ) {
            for ( int j = 1 ; j <= n ; ++j ) {
                int u = min(i+1,m);
                int v = min(j+1,n);
                int k = max(i-1,1);
                int l = max(j-1,1);
                int num = (v-l+1)*(u-k+1);
                img[i-1][j-1] = cal(sum,k,l,u,v)/num;
            }
        }
        return img;
    }
};
