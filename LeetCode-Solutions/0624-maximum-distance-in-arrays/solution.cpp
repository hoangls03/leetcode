class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = -1e9;
        int max_num = -1e9;
        int min_num = 1e9;
        for ( auto a : arrays ) {
            int n = a.size();
            ans = max({ans,max_num-a[0],a[n-1]-min_num});
            max_num = max(max_num,a[n-1]);
            min_num = min(min_num,a[0]);
        }
        return ans;
    }
};
