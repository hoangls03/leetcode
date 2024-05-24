class Solution {
public:
    int dfs( int pos_ring, int pos_key, int m, int n, string& ring, string& key, vector<vector<int>>& dp) {
        if ( pos_ring >= m || pos_key >= n ) return 0;
        if ( dp[pos_ring][pos_key] != 1e9 ) return dp[pos_ring][pos_key]; // if we already visited return that value
        int ans = 1e9;
        for ( int i = 0 ; i < m ; ++i ) {
            if ( ring[i] == key[pos_key] ) { // get all of the positions equal to the key character
                int temp = min(abs(pos_ring-i),m-abs(pos_ring-i)); // get the min of go clockwise or counter clockwise
                ans = min(ans,dfs(i,pos_key+1,m,n,ring,key,dp) + temp); // compare all of them how to get from that position to beyond(the end of the string)
            }
        }
        dp[pos_ring][pos_key] = ans;
        return ans;
    }
    int findRotateSteps(string ring, string key) {
        int pos_ring = 0;
        int pos_key = 0;
        int m = ring.size();
        int n = key.size();
        vector<vector<int>> dp(max(m,n)+5,vector<int>(max(m,n)+5,1e9));
        int ans = dfs(pos_ring,pos_key,m,n, ring, key, dp); 
        return ans + n; // add the number of press the button
    }
};
