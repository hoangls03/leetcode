class Solution {
public:
    void write( int n, vector<int>& bt, string& ans, map<string,int>& mp) {
        if ( ans != "") return ;
        string temp = "";
        for ( int i = 0 ; i < n ; ++i ) {
            temp += bt[i] + '0';
        }
        if ( mp[temp] == 0 ) {
            ans = temp;
        }
    }
    void bk( int i, int n, vector<int>& bt, string& ans, map<string,int>& mp) {
        for( int j = 0 ; j < 2 && ans == ""; ++j ) {
            bt[i] = j;
            if ( i == n - 1 ) write(n,bt,ans,mp);
            else if ( i >= n ) break;
            else bk(i+1,n,bt,ans,mp);
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int> mp;
        for ( auto s : nums ) {
            mp[s]++;
        }
        int n = nums[0].size();
        vector<int> bt(n,0);
        string ans = "";
        bk(0,n,bt,ans,mp);
        return ans;
    }
};
