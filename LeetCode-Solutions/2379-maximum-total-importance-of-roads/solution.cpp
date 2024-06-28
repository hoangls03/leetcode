class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> mark(n+5,0);
        for ( int i = 0 ; i < roads.size() ; ++i ) { 
            mark[roads[i][0]]++;
            mark[roads[i][1]]++;
        }
        sort(mark.begin(),mark.end());
        long long ans = 0;
        long long pos = n;
        for ( int i = mark.size() - 1 ; i >= 0 && pos > 0 ; --i ) {
            ans += pos*mark[i];
            pos--;
        }
        return ans;
    }
};
