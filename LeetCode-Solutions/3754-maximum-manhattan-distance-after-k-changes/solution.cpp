class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int N = 0, W = 0, S = 0, E = 0;
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            N += (s[i] == 'N');
            W += (s[i] == 'W');
            S += (s[i] == 'S');
            E += (s[i] == 'E');
            int ver = abs(S-N);
            int hor = abs(W-E);
            int dis = ver + hor;
            ans = max(ans,dis + min(2*k,i + 1 - dis));
        }
        return ans;    
    }
};
