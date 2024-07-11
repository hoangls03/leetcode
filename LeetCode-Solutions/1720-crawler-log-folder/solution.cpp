class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for ( auto i : logs ) {
            if ( i == "../" && ans > 0 ) ans--;
            if ( i[0] != '.' ) ans++; 
        }
        return ans;
    }
};
